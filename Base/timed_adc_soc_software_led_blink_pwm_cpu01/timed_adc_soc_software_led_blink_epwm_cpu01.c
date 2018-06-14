//###########################################################################
//
// FILE:    LedBlink.c
//
// TITLE:   LED Blink Getting Started Program.
//
//! \addtogroup cpu01_example_list
//! <h1>LED Blink Getting Started Program (timed_led_blink)</h1>
//!
//!  This example configures CPU Timer0 for a 500 msec period, and toggles the
//!  GPIO34 LED once per interrupt. For testing purposes, this example
//!  also increments a counter each time the timer asserts an interrupt.
//!
//!  \b Watch \b Variables \n
//!  - CpuTimer0.InterruptCount
//!
//!  Monitor the GPIO34 LED blink on (for 500 msec) and off (for 500 msec) on
//!  the F2837xS control card.
//!
//
//###########################################################################
//
// FILE:   adc_soc_software_cpu01.c
//
// TITLE:  ADC software triggering for F2837xS.
//
//! \addtogroup cpu01_example_list
//! <h1> ADC SOC Software Force (adc_soc_software)</h1>
//!
//! This example converts some voltages on ADCA and ADCB  based on a software
//! trigger.
//!
//! After the program runs, the memory will contain:
//!
//! - \b AdcaResult0 \b: a digital representation of the voltage on pin A2\n
//! - \b AdcaResult1 \b: a digital representation of the voltage on pin A3\n
//! - \b AdcbResult0 \b: a digital representation of the voltage on pin B2\n
//! - \b AdcbResult1 \b: a digital representation of the voltage on pin B3\n
//!
//! Note: The software triggers for the two ADCs happen sequentially, so the
//! two ADCs will run asynchronously.

//###########################################################################
//
// FILE:   epwm_updown_aq_cpu01.c
//
// TITLE:  Action Qualifier Module - Using up/down count.
//
//! \addtogroup cpu01_example_list
//! <h1> EPWM Action Qualifier (epwm_updown_aq)</h1>
//!
//! This example configures ePWM1, ePWM2, ePWM3 to produce an
//! waveform with independent modulation on EPWMxA and
//! EPWMxB.
//!
//! The compare values CMPA and CMPB are modified within the ePWM's ISR.
//!
//! The TB counter is in up/down count mode for this example.
//!
//! View the EPWM1A/B(PA0_GPIO0 & PA1_GPIO1), EPWM2A/B(PA2_GPIO2 & PA3_GPIO3)
//! and EPWM3A/B(PA4_GPIO4 & PA5_GPIO5) waveforms via an oscilloscope.
//!
//

//###########################################################################
// $TI Release: F2837xS Support Library v3.04.00.00 $
// $Release Date: Sun Mar 25 13:27:27 CDT 2018 $
// $Copyright:
// Copyright (C) 2014-2018 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

//
// Included Files
//
#include "F28x_Project.h"
#include "ePWM.h"

//
// Function Prototypes
//
__interrupt void cpu_timer0_isr(void);
void ConfigureADC(void);
void SetupADCSoftware(void);

void InitEPwmGpio(void);
void InitEPwm1Example(void);
void InitEPwm2Example(void);
void InitEPwm3Example(void);
__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm3_isr(void);
void update_compare(EPWM_INFO*);


//
// Globals
//

EPWM_INFO epwm1_info;
EPWM_INFO epwm2_info;
EPWM_INFO epwm3_info;

//
// Globals
//
Uint16 AdcaResult0;
Uint16 AdcaResult1;
Uint16 AdcbResult0;
Uint16 AdcbResult1;


void main(void)
{
//
// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the F2837xS_SysCtrl.c file.
//
   InitSysCtrl();

//
// Step 2. Initialize GPIO:
// This example function is found in the F2837xS_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
//
// InitGpio();  // Skipped for this example

//
// enable PWM1, PWM2 and PWM3
//
    CpuSysRegs.PCLKCR2.bit.EPWM1=1;
    CpuSysRegs.PCLKCR2.bit.EPWM2=1;
    CpuSysRegs.PCLKCR2.bit.EPWM3=1;
   //
   // For this case just init GPIO pins for ePWM1, ePWM2, ePWM3
   // These functions are in the F2837xS_EPwm.c file
   //
    InitEPwmGpio();
//
// Step 3. Clear all __interrupts and initialize PIE vector table:
//
   DINT;

//
// Initialize the PIE control registers to their default state.
// The default state is all PIE __interrupts disabled and flags
// are cleared.
// This function is found in the F2837xS_PieCtrl.c file.
//
   InitPieCtrl();

//
// Disable CPU __interrupts and clear all CPU __interrupt flags:
//
   IER = 0x0000;
   IFR = 0x0000;

//
// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table, even if the __interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in F2837xS_DefaultIsr.c.
// This function is found in F2837xS_PieVect.c.
//
   InitPieVectTable();

//
// Interrupts that are used in this example are re-mapped to
// ISR functions found within this file.
//
   EALLOW;  // This is needed to write to EALLOW protected registers
   PieVectTable.TIMER0_INT = &cpu_timer0_isr;
   PieVectTable.EPWM1_INT = &epwm1_isr;
   PieVectTable.EPWM2_INT = &epwm2_isr;
   PieVectTable.EPWM3_INT = &epwm3_isr;
   EDIS;    // This is needed to disable write to EALLOW protected registers

//
// Step 4. Initialize the Device Peripheral. This function can be
//         found in F2837xS_CpuTimers.c
//
   InitCpuTimers();   // For this example, only initialize the Cpu Timers

//
// Configure CPU-Timer 0 to __interrupt every 500 milliseconds:
// 60MHz CPU Freq, 50 millisecond Period (in uSeconds)
//
   ConfigCpuTimer(&CpuTimer0, 60, 500000);

//
// To ensure precise timing, use write-only instructions to write to the entire
// register. Therefore, if any of the configuration bits are changed in
// ConfigCpuTimer and InitCpuTimers (in F2837xS_cputimervars.h), the below
// settings must also be updated.
//
   CpuTimer0Regs.TCR.all = 0x4001;

//
// Step 5. User specific code, enable __interrupts:
// Configure GPIO34 as a GPIO output pin
//
   EALLOW;
   GpioCtrlRegs.GPADIR.bit.GPIO12 = 1; // LED D9
   GpioCtrlRegs.GPADIR.bit.GPIO13 = 1; // LED D10
   // Set LED data
   GpioDataRegs.GPADAT.bit.GPIO12 = 1; // LED D9
   GpioDataRegs.GPADAT.bit.GPIO13 = 1; // LED D10
   EDIS;

   //
   // For this example, only initialize the ePWM
   //
   EALLOW;
   CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
   EDIS;

   InitEPwm1Example();
   InitEPwm2Example();
   InitEPwm3Example();

   EALLOW;
   CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
   EDIS;

//
// Enable CPU INT1 which is connected to CPU-Timer 0:
//
   IER |= M_INT1;

//
// Enable CPU INT3 which is connected to EPWM1-3 INT:
//
       IER |= M_INT3;

//
// Enable TINT0 in the PIE: Group 1 __interrupt 7
//
   PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
//
// Enable EPWM INTn in the PIE: Group 3 interrupt 1-3
//
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx3 = 1;

//
// Enable global Interrupts and higher priority real-time debug events:
//
   EINT;   // Enable Global __interrupt INTM
   ERTM;   // Enable Global realtime __interrupt DBGM


   //Configure the ADCs and power them up
    ConfigureADC();
   //Setup the ADCs for software conversions
    SetupADCSoftware();


//
// Step 6. IDLE loop. Just sit and loop forever (optional):
//
    for(;;){
           asm ("          NOP");
       }
}



//
// cpu_timer0_isr - CPU Timer0 ISR that toggles GPIO32 once per 500ms
//
__interrupt void cpu_timer0_isr(void)
{
   CpuTimer0.InterruptCount++;
   GpioDataRegs.GPATOGGLE.bit.GPIO12 = 1; // LED D9
   GpioDataRegs.GPATOGGLE.bit.GPIO13 = 1; // LED D10


    //convert, wait for completion, and store results
    //start conversions immediately via software, ADCA
    //
    AdcaRegs.ADCSOCFRC1.all = 0x0003; //SOC0 and SOC1

    //
    //start conversions immediately via software, ADCB
    //
    AdcbRegs.ADCSOCFRC1.all = 0x0003; //SOC0 and SOC1

    //
    //wait for ADCA to complete, then acknowledge flag
    //
    while(AdcaRegs.ADCINTFLG.bit.ADCINT1 == 0);
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    //
    //wait for ADCB to complete, then acknowledge flag
    //
    while(AdcbRegs.ADCINTFLG.bit.ADCINT1 == 0);
    AdcbRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    //store results
    AdcaResult0 = AdcaResultRegs.ADCRESULT0;
    AdcaResult1 = AdcaResultRegs.ADCRESULT1;
    AdcbResult0 = AdcbResultRegs.ADCRESULT0;
    AdcbResult1 = AdcbResultRegs.ADCRESULT1;

    //
    //at this point, conversion results are stored in
    //AdcaResult0, AdcaResult1, AdcbResult0, and AdcbResult1
    //






   //
   // Acknowledge this __interrupt to receive more __interrupts from group 1
   //
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}



//
// End of file
//
