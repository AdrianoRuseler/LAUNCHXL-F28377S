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

//
// Defines LAUNCHXL-F28377S SYSCLKOUT = 200MHz
//


// #define EPWMCLK

#define FCLK       100000000L
#define FS_CONV      19980L
#define TIMER_PWM (unsigned int)(FCLK/(2*FS_CONV))


#define EPWM2_TIMER_TBPRD  TIMER_PWM  // Period register
#define EPWM2_MAX_CMPA     1950
#define EPWM2_MIN_CMPA       50
#define EPWM2_MAX_CMPB     1950
#define EPWM2_MIN_CMPB       50

#define EPWM6_TIMER_TBPRD  2000  // Period register
#define EPWM6_MAX_CMPA     1950
#define EPWM6_MIN_CMPA       50
#define EPWM6_MAX_CMPB     1950
#define EPWM6_MIN_CMPB       50

#define EPWM7_TIMER_TBPRD  2000  // Period register
#define EPWM7_MAX_CMPA     1950
#define EPWM7_MIN_CMPA       50
#define EPWM7_MAX_CMPB     1950
#define EPWM7_MIN_CMPB       50

#define EPWM8_TIMER_TBPRD  2000  // Period register
#define EPWM8_MAX_CMPA     1950
#define EPWM8_MIN_CMPA       50
#define EPWM8_MAX_CMPB     1950
#define EPWM8_MIN_CMPB       50

#define EPWM_CMP_UP           1
#define EPWM_CMP_DOWN         0

//
// Globals
//
typedef struct
{
    volatile struct EPWM_REGS *EPwmRegHandle;
    Uint16 EPwm_CMPA_Direction;
    Uint16 EPwm_CMPB_Direction;
    Uint16 EPwmTimerIntCount;
    Uint16 EPwmMaxCMPA;
    Uint16 EPwmMinCMPA;
    Uint16 EPwmMaxCMPB;
    Uint16 EPwmMinCMPB;
}EPWM_INFO;


EPWM_INFO epwm2_info;
EPWM_INFO epwm6_info;
EPWM_INFO epwm7_info;
EPWM_INFO epwm8_info;
//
// Function Prototypes
//

void InitEPwm2Example(void);
void InitEPwm6Example(void);
void InitEPwm7Example(void);
void InitEPwm8Example(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm6_isr(void);
__interrupt void epwm7_isr(void);
__interrupt void epwm8_isr(void);
void update_compare(EPWM_INFO*);

//
// Main
//
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
//    InitGpio();

//
// enable PWM2, PWM6, PWM7 and PWM8
//

    CpuSysRegs.PCLKCR2.bit.EPWM2=1;
    CpuSysRegs.PCLKCR2.bit.EPWM6=1;
    CpuSysRegs.PCLKCR2.bit.EPWM7=1;
    CpuSysRegs.PCLKCR2.bit.EPWM8=1;

//
// For this case just init GPIO pins for PWM2, PWM6, PWM7 and PWM8
// These functions are in the F2837xS_EPwm.c file
//

    InitEPwm2Gpio(); //
    InitEPwm6Gpio();
    InitEPwm7Gpio();
    InitEPwm8Gpio();

//
// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts
//
    DINT;

//
// Initialize the PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.
// This function is found in the F2837xS_PieCtrl.c file.
//
    InitPieCtrl();

//
// Disable CPU interrupts and clear all CPU interrupt flags:
//
    IER = 0x0000;
    IFR = 0x0000;

//
// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table, even if the interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in F2837xS_DefaultIsr.c.
// This function is found in F2837xS_PieVect.c.
//
    InitPieVectTable();

//
// Interrupts that are used in this example are re-mapped to
// ISR functions found within this file.
//
    EALLOW; // This is needed to write to EALLOW protected registers
    PieVectTable.EPWM2_INT = &epwm2_isr;
    PieVectTable.EPWM6_INT = &epwm6_isr;
    PieVectTable.EPWM7_INT = &epwm7_isr;
    PieVectTable.EPWM8_INT = &epwm8_isr;
    EDIS;   // This is needed to disable write to EALLOW protected registers

//
// For this example, only initialize the ePWM
//
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    EDIS;
    InitEPwm2Example();
    InitEPwm6Example();
    InitEPwm7Example();
    InitEPwm8Example();
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;

//
// Step 4. User specific code, enable interrupts:
//

//
// Enable CPU INT3 which is connected to EPWM1-3 INT:
//
    IER |= M_INT3;

//
// Enable EPWM INTn in the PIE: Group 3 interrupt 1-3
//

    PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx6 = 1; // ePWM6
    PieCtrlRegs.PIEIER3.bit.INTx7 = 1; // ePWM7
    PieCtrlRegs.PIEIER3.bit.INTx8 = 1; // ePWM8

//
// Enable global Interrupts and higher priority real-time debug events:
//
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM

//
// Step 5. IDLE loop. Just sit and loop forever (optional):
//
    for(;;)
    {
        asm ("    NOP");
    }
}


//
// epwm2_isr - EPWM2 ISR
//
__interrupt void epwm2_isr(void)
{
    //
    // Update the CMPA and CMPB values
    //
    update_compare(&epwm2_info);

    //
    // Clear INT flag for this timer
    //
    EPwm2Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}


//
// epwm6_isr - EPWM6 ISR
//
__interrupt void epwm6_isr(void)
{
    //
    // Update the CMPA and CMPB values
    //
    update_compare(&epwm6_info);

    //
    // Clear INT flag for this timer
    //
    EPwm6Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

//
// epwm7_isr - EPWM7 ISR
//
__interrupt void epwm7_isr(void)
{
    //
    // Update the CMPA and CMPB values
    //
    update_compare(&epwm7_info);

    //
    // Clear INT flag for this timer
    //
    EPwm7Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

//
// epwm8_isr - EPWM8 ISR
//
__interrupt void epwm8_isr(void)
{

    // Update the CMPA and CMPB values
    update_compare(&epwm8_info);

    // Clear INT flag for this timer
    EPwm8Regs.ETCLR.bit.INT = 1;

    // Acknowledge this interrupt to receive more interrupts from group 3
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

//
// InitEPwm2Example - Initialize EPWM2 configuration
//
void InitEPwm2Example()
{
    //
    // Setup TBCLK
    //
    EPwm2Regs.TBPRD = EPWM2_TIMER_TBPRD;         // Set timer period 801 TBCLKs
    EPwm2Regs.TBPHS.bit.TBPHS = 0x0000;          // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                    // Clear counter

    //
    // Set Compare values
    //
    EPwm2Regs.CMPA.bit.CMPA = EPWM2_MIN_CMPA;    // Set compare A value
    EPwm2Regs.CMPB.bit.CMPB = EPWM2_MIN_CMPB;    // Set Compare B value

    //
    // Setup counter mode
    //
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up and down
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    //
    // Setup shadowing
    //
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // Load on Zero
    EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    //
    // Set actions
    //
    EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;         // Set PWM2A on event A, up
                                               // count
    EPwm2Regs.AQCTLA.bit.CBD = AQ_CLEAR;       // Clear PWM2A on event B, down
                                               // count

    EPwm2Regs.AQCTLB.bit.ZRO = AQ_CLEAR;       // Clear PWM2B on zero
    EPwm2Regs.AQCTLB.bit.PRD = AQ_SET;         // Set PWM2B on period

    //
    // Interrupt where we will change the Compare Values
    //
    EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
    EPwm2Regs.ETSEL.bit.INTEN = 1;               // Enable INT
    EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;          // Generate INT on 3rd event

    //
    // Information this example uses to keep track
    // of the direction the CMPA/CMPB values are
    // moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm2_info.EPwm_CMPA_Direction = EPWM_CMP_UP;  // Start by increasing CMPA
    epwm2_info.EPwm_CMPB_Direction = EPWM_CMP_UP;  // & increasing CMPB
    epwm2_info.EPwmTimerIntCount = 0;              // Zero the interrupt counter
    epwm2_info.EPwmRegHandle = &EPwm2Regs;         // Set the pointer to the
                                                   // ePWM module
    epwm2_info.EPwmMaxCMPA = EPWM2_MAX_CMPA;       // Setup min/max CMPA/CMPB
                                                   // values
    epwm2_info.EPwmMinCMPA = EPWM2_MIN_CMPA;
    epwm2_info.EPwmMaxCMPB = EPWM2_MAX_CMPB;
    epwm2_info.EPwmMinCMPB = EPWM2_MIN_CMPB;
}

//
// InitEPwm3Example - Initialize EPWM3 configuration
//
/*
void InitEPwm3Example(void)
{
    //
    // Setup TBCLK
    //
    EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up/down and down
    EPwm3Regs.TBPRD = EPWM3_TIMER_TBPRD;           // Set timer period
    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm3Regs.TBPHS.bit.TBPHS = 0x0000;            // Phase is 0
    EPwm3Regs.TBCTR = 0x0000;                      // Clear counter
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    //
    // Setup shadow register load on ZERO
    //
    EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    //
    // Set Compare values
    //
    EPwm3Regs.CMPA.bit.CMPA = EPWM3_MIN_CMPA;   // Set compare A value
    EPwm3Regs.CMPB.bit.CMPB = EPWM3_MAX_CMPB;   // Set Compare B value

    //
    // Set Actions
    //
    EPwm3Regs.AQCTLA.bit.PRD = AQ_SET;         // Set PWM3A on period
    EPwm3Regs.AQCTLA.bit.CBD = AQ_CLEAR;       // Clear PWM3A on event B, down
                                               // count

    EPwm3Regs.AQCTLB.bit.PRD = AQ_CLEAR;       // Clear PWM3A on period
    EPwm3Regs.AQCTLB.bit.CAU = AQ_SET;         // Set PWM3A on event A, up
                                               // count

    //
    // Interrupt where we will change the Compare Values
    //
    EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
    EPwm3Regs.ETSEL.bit.INTEN = 1;               // Enable INT
    EPwm3Regs.ETPS.bit.INTPRD = ET_3RD;          // Generate INT on 3rd event

    //
    // Information this example uses to keep track
    // of the direction the CMPA/CMPB values are
    // moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm3_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA
    epwm3_info.EPwm_CMPB_Direction = EPWM_CMP_DOWN; // & decreasing CMPB
    epwm3_info.EPwmTimerIntCount = 0;               // Zero the interrupt counter
    epwm3_info.EPwmRegHandle = &EPwm3Regs;          // Set the pointer to the
                                                    // ePWM module
    epwm3_info.EPwmMaxCMPA = EPWM3_MAX_CMPA;        // Setup min/max CMPA/CMPB
                                                    // values
    epwm3_info.EPwmMinCMPA = EPWM3_MIN_CMPA;
    epwm3_info.EPwmMaxCMPB = EPWM3_MAX_CMPB;
    epwm3_info.EPwmMinCMPB = EPWM3_MIN_CMPB;
}
*/

//
// InitEPwm6Example - Initialize EPWM6 configuration
//
void InitEPwm6Example()
{
    //
    // Setup TBCLK
    //
    EPwm6Regs.TBPRD = EPWM6_TIMER_TBPRD;       // Set timer period 801 TBCLKs
    EPwm6Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm6Regs.TBCTR = 0x0000;                  // Clear counter

    //
    // Set Compare values
    //
    EPwm6Regs.CMPA.bit.CMPA = EPWM6_MIN_CMPA;    // Set compare A value
    EPwm6Regs.CMPB.bit.CMPB = EPWM6_MAX_CMPB;    // Set Compare B value

    //
    // Setup counter mode
    //
    EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up and down
    EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    //
    // Setup shadowing
    //
    EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // Load on Zero
    EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    //
    // Set actions
    //
    EPwm6Regs.AQCTLA.bit.CAU = AQ_SET;            // Set PWM1A on event A, up
                                                  // count
    EPwm6Regs.AQCTLA.bit.CAD = AQ_CLEAR;          // Clear PWM1A on event A,
                                                  // down count

    EPwm6Regs.AQCTLB.bit.CBU = AQ_SET;            // Set PWM1B on event B, up
                                                  // count
    EPwm6Regs.AQCTLB.bit.CBD = AQ_CLEAR;          // Clear PWM1B on event B,
                                                  // down count

    //
    // Interrupt where we will change the Compare Values
    //
    EPwm6Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
    EPwm6Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm6Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

    //
    // Information this example uses to keep track
    // of the direction the CMPA/CMPB values are
    // moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm6_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA
    epwm6_info.EPwm_CMPB_Direction = EPWM_CMP_DOWN; // & decreasing CMPB
    epwm6_info.EPwmTimerIntCount = 0;               // Zero the interrupt counter
    epwm6_info.EPwmRegHandle = &EPwm6Regs;          // Set the pointer to the
                                                    // ePWM module
    epwm6_info.EPwmMaxCMPA = EPWM6_MAX_CMPA;        // Setup min/max CMPA/CMPB
                                                    // values
    epwm6_info.EPwmMinCMPA = EPWM6_MIN_CMPA;
    epwm6_info.EPwmMaxCMPB = EPWM6_MAX_CMPB;
    epwm6_info.EPwmMinCMPB = EPWM6_MIN_CMPB;
}


//
// InitEPwm7Example - Initialize EPWM7 configuration
//
void InitEPwm7Example()
{
    //
    // Setup TBCLK
    //
    EPwm7Regs.TBPRD = EPWM7_TIMER_TBPRD;       // Set timer period 801 TBCLKs
    EPwm7Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm7Regs.TBCTR = 0x0000;                  // Clear counter

    //
    // Set Compare values
    //
    EPwm7Regs.CMPA.bit.CMPA = EPWM7_MIN_CMPA;    // Set compare A value
    EPwm7Regs.CMPB.bit.CMPB = EPWM7_MAX_CMPB;    // Set Compare B value

    //
    // Setup counter mode
    //
    EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up and down
    EPwm7Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm7Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm7Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    //
    // Setup shadowing
    //
    EPwm7Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm7Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm7Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // Load on Zero
    EPwm7Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    //
    // Set actions
    //
    EPwm7Regs.AQCTLA.bit.CAU = AQ_SET;            // Set PWM1A on event A, up
                                                  // count
    EPwm7Regs.AQCTLA.bit.CAD = AQ_CLEAR;          // Clear PWM1A on event A,
                                                  // down count

    EPwm7Regs.AQCTLB.bit.CBU = AQ_SET;            // Set PWM1B on event B, up
                                                  // count
    EPwm7Regs.AQCTLB.bit.CBD = AQ_CLEAR;          // Clear PWM1B on event B,
                                                  // down count

    //
    // Interrupt where we will change the Compare Values
    //
    EPwm7Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
    EPwm7Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm7Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

    //
    // Information this example uses to keep track
    // of the direction the CMPA/CMPB values are
    // moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm7_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA
    epwm7_info.EPwm_CMPB_Direction = EPWM_CMP_DOWN; // & decreasing CMPB
    epwm7_info.EPwmTimerIntCount = 0;               // Zero the interrupt counter
    epwm7_info.EPwmRegHandle = &EPwm7Regs;          // Set the pointer to the
                                                    // ePWM module
    epwm7_info.EPwmMaxCMPA = EPWM7_MAX_CMPA;        // Setup min/max CMPA/CMPB
                                                    // values
    epwm7_info.EPwmMinCMPA = EPWM7_MIN_CMPA;
    epwm7_info.EPwmMaxCMPB = EPWM7_MAX_CMPB;
    epwm7_info.EPwmMinCMPB = EPWM7_MIN_CMPB;
}

//
// InitEPwm8Example - Initialize EPWM8 configuration
//
void InitEPwm8Example()
{
    //
    // Setup TBCLK
    //
    EPwm8Regs.TBPRD = EPWM8_TIMER_TBPRD;       // Set timer period 801 TBCLKs
    EPwm8Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm8Regs.TBCTR = 0x0000;                  // Clear counter

    //
    // Set Compare values
    //
    EPwm8Regs.CMPA.bit.CMPA = EPWM8_MIN_CMPA;    // Set compare A value
    EPwm8Regs.CMPB.bit.CMPB = EPWM8_MAX_CMPB;    // Set Compare B value

    //
    // Setup counter mode
    //
    EPwm8Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up and down
    EPwm8Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm8Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm8Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    //
    // Setup shadowing
    //
    EPwm8Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm8Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm8Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // Load on Zero
    EPwm8Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    //
    // Set actions
    //
    EPwm8Regs.AQCTLA.bit.CAU = AQ_SET;            // Set PWM1A on event A, up
                                                  // count
    EPwm8Regs.AQCTLA.bit.CAD = AQ_CLEAR;          // Clear PWM1A on event A,
                                                  // down count

    EPwm8Regs.AQCTLB.bit.CBU = AQ_SET;            // Set PWM1B on event B, up
                                                  // count
    EPwm8Regs.AQCTLB.bit.CBD = AQ_CLEAR;          // Clear PWM1B on event B,
                                                  // down count

    //
    // Interrupt where we will change the Compare Values
    //
    EPwm8Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
    EPwm8Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm8Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

    //
    // Information this example uses to keep track
    // of the direction the CMPA/CMPB values are
    // moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm8_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA
    epwm8_info.EPwm_CMPB_Direction = EPWM_CMP_DOWN; // & decreasing CMPB
    epwm8_info.EPwmTimerIntCount = 0;               // Zero the interrupt counter
    epwm8_info.EPwmRegHandle = &EPwm8Regs;          // Set the pointer to the
                                                    // ePWM module
    epwm8_info.EPwmMaxCMPA = EPWM8_MAX_CMPA;        // Setup min/max CMPA/CMPB
                                                    // values
    epwm8_info.EPwmMinCMPA = EPWM8_MIN_CMPA;
    epwm8_info.EPwmMaxCMPB = EPWM8_MAX_CMPB;
    epwm8_info.EPwmMinCMPB = EPWM8_MIN_CMPB;
}

//
// update_compare - Update the PWM compare values
//
void update_compare(EPWM_INFO *epwm_info)
{
    //
    // Every 10'th interrupt, change the CMPA/CMPB values
    //
    if(epwm_info->EPwmTimerIntCount == 10)
    {
        epwm_info->EPwmTimerIntCount = 0;

        //
        // If we were increasing CMPA, check to see if
        // we reached the max value.  If not, increase CMPA
        // else, change directions and decrease CMPA
        //
        if(epwm_info->EPwm_CMPA_Direction == EPWM_CMP_UP)
        {
            if(epwm_info->EPwmRegHandle->CMPA.bit.CMPA <
               epwm_info->EPwmMaxCMPA)
            {
                epwm_info->EPwmRegHandle->CMPA.bit.CMPA++;
            }
            else
            {
                epwm_info->EPwm_CMPA_Direction = EPWM_CMP_DOWN;
                epwm_info->EPwmRegHandle->CMPA.bit.CMPA--;
            }
        }

        //
        // If we were decreasing CMPA, check to see if
        // we reached the min value.  If not, decrease CMPA
        // else, change directions and increase CMPA
        //
        else
        {
            if(epwm_info->EPwmRegHandle->CMPA.bit.CMPA ==
               epwm_info->EPwmMinCMPA)
            {
                epwm_info->EPwm_CMPA_Direction = EPWM_CMP_UP;
                epwm_info->EPwmRegHandle->CMPA.bit.CMPA++;
            }
            else
            {
                epwm_info->EPwmRegHandle->CMPA.bit.CMPA--;
            }
        }

        //
        // If we were increasing CMPB, check to see if
        // we reached the max value.  If not, increase CMPB
        // else, change directions and decrease CMPB
        //
        if(epwm_info->EPwm_CMPB_Direction == EPWM_CMP_UP)
        {
            if(epwm_info->EPwmRegHandle->CMPB.bit.CMPB < epwm_info->EPwmMaxCMPB)
            {
                epwm_info->EPwmRegHandle->CMPB.bit.CMPB++;
            }
            else
            {
                epwm_info->EPwm_CMPB_Direction = EPWM_CMP_DOWN;
                epwm_info->EPwmRegHandle->CMPB.bit.CMPB--;
            }
        }

        //
        // If we were decreasing CMPB, check to see if
        // we reached the min value.  If not, decrease CMPB
        // else, change directions and increase CMPB
        //
        else
        {
            if(epwm_info->EPwmRegHandle->CMPB.bit.CMPB == epwm_info->EPwmMinCMPB)
            {
                epwm_info->EPwm_CMPB_Direction = EPWM_CMP_UP;
                epwm_info->EPwmRegHandle->CMPB.bit.CMPB++;
            }
            else
            {
                epwm_info->EPwmRegHandle->CMPB.bit.CMPB--;
            }
        }
    }
    else
    {
        epwm_info->EPwmTimerIntCount++;
    }

    return;
}

//
// End of file
//
