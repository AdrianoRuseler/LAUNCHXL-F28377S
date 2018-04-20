//###########################################################################
//
// FILE:   adc_ppb_offset_cpu01.c
//
// TITLE:  ADC offset adjust using post-processing block for F2837xS.
//
//! \addtogroup cpu01_example_list
//! <h1> ADC PPB Offset (adc_ppb_offset)</h1>
//!
//! This example software triggers the ADC.  Some SOCs have automatic offset
//! adjustment applied by the post-processing block.
//!
//! After the program runs, the memory will contain:\n
//!
//! - \b AdcaResult \b: a digital representation of the voltage on pin A0
//! - \b AdcaResult_offsetAdjusted \b : a digital representation of the voltage
//!      on pin A0, plus 100 LSBs of automatically added offset
//! - \b AdcbResult \b: a digital representation of the voltage on pin B0
//! - \b AdcbResult_offsetAdjusted \b : a digital representation of the voltage
//!      on pin B0 minus 100 LSBs of automatically added offset
//
//###########################################################################
// $TI Release: F2837xS Support Library v210 $
// $Release Date: Tue Nov  1 15:35:23 CDT 2016 $
// $Copyright: Copyright (C) 2014-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

//
// Included Files
//
#include "F28x_Project.h"

//
// Function Prototypes
//
void ConfigureADC(void);
void SetupADCSoftware(void);
void SetupPPBOffset(int16 aOffset, int16 bOffset);

//
// Globals
//
Uint16 AdcaResult;
Uint16 AdcaResult_offsetAdjusted;
Uint16 AdcbResult;
Uint16 AdcbResult_offsetAdjusted;

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
    InitGpio();

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
// Enable global Interrupts and higher priority real-time debug events:
//
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM

//
//Configure the ADCs and power them up
//
    ConfigureADC();

//
//Setup the ADCs for software conversions
//
    SetupADCSoftware();

//
//Setup PPB offset correction
//conversion on channel A will subtract 100
//conversion on channel B will add 100
//
    SetupPPBOffset(100, -100);

//
//take conversions indefinitely in loop
//
    do
    {
        //
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

        //
        //store results
        //
        AdcaResult = AdcaResultRegs.ADCRESULT0;
        AdcaResult_offsetAdjusted = AdcaResultRegs.ADCRESULT1;
        AdcbResult = AdcbResultRegs.ADCRESULT0;
        AdcbResult_offsetAdjusted = AdcbResultRegs.ADCRESULT1;

        //
        //software breakpoint, hit run again to get updated conversions
        //
        asm("   ESTOP0");

    }while(1);
}

//
// ConfigureADC - Write ADC configurations and power up the ADC for both
//                ADC A and ADC B
//
void ConfigureADC(void)
{
    EALLOW;

    //
    //write configurations
    //
    AdcaRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK divider to /4
    AdcbRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK divider to /4
    AdcSetMode(ADC_ADCA, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);
    AdcSetMode(ADC_ADCB, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);

    //
    //Set pulse positions to late
    //
    AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;
    AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1;

    //
    //power up the ADCs
    //
    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;
    AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1;

    //
    //delay for 1ms to allow ADC time to power up
    //
    DELAY_US(1000);

    EDIS;
}

//
// SetupADCSoftware - Configure ADC SOC and acquisition window
//
void SetupADCSoftware(void)
{
    Uint16 acqps;

    //
    //determine minimum acquisition window (in SYSCLKS) based on resolution
    //
    if(ADC_RESOLUTION_12BIT == AdcaRegs.ADCCTL2.bit.RESOLUTION)
    {
        acqps = 14; //75ns
    }
    else //resolution is 16-bit
    {
        acqps = 63; //320ns
    }

    //
    //Select the channels to convert and end of conversion flag
    //ADCA
    //
    EALLOW;
    AdcaRegs.ADCSOC0CTL.bit.CHSEL = 0;  //SOC0 will convert pin A0
    AdcaRegs.ADCSOC0CTL.bit.ACQPS = acqps; //sample window is 100 SYSCLK cycles
    AdcaRegs.ADCSOC1CTL.bit.CHSEL = 0;  //SOC1 will convert pin A0
    AdcaRegs.ADCSOC1CTL.bit.ACQPS = acqps; //sample window is 100 SYSCLK cycles
    AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 1; //end of SOC1 will set INT1 flag
    AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1;   //enable INT1 flag
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; //make sure INT1 flag is cleared
    //
    //ADCB
    //
    AdcbRegs.ADCSOC0CTL.bit.CHSEL = 0;  //SOC0 will convert pin B0
    AdcbRegs.ADCSOC0CTL.bit.ACQPS = acqps; //sample window is 100 SYSCLK cycles
    AdcbRegs.ADCSOC1CTL.bit.CHSEL = 0;  //SOC1 will convert pin B0
    AdcbRegs.ADCSOC1CTL.bit.ACQPS = acqps; //sample window is 100 SYSCLK cycles
    AdcbRegs.ADCINTSEL1N2.bit.INT1SEL = 1; //end of SOC1 will set INT1 flag
    AdcbRegs.ADCINTSEL1N2.bit.INT1E = 1;   //enable INT1 flag
    AdcbRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; //make sure INT1 flag is cleared
    EDIS;
}

//
// SetupPPBOffset - Configure PPB for SOC
//
void SetupPPBOffset(int16 aOffset, int16 bOffset)
{
    AdcaRegs.ADCPPB1CONFIG.bit.CONFIG = 1; //PPB1 is associated with SOC1
    AdcaRegs.ADCPPB1OFFCAL.all = aOffset;  //PPB1 will subtract OFFCAL value
                                           //to associated SOC

    AdcbRegs.ADCPPB1CONFIG.bit.CONFIG = 1; //PPB1 is associated with SOC1
    AdcbRegs.ADCPPB1OFFCAL.all = bOffset;  //PPB1 will subtract OFFCAL value
                                           //to associated SOC
}

//
// End of file
//
