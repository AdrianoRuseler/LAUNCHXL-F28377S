//###########################################################################
//
// FILE:   buffdac_random_cpu01.c
//
// TITLE:  Buffered DAC Random Output Example for F2837xS.
//
//! \addtogroup cpu01_example_list
//! <h1> Buffered DAC Random (buffdac_random) </h1>
//!
//! This example generates random voltages on the buffered DAC output,
//! DACOUTA/ADCINA0 (HSEC Pin 9) and uses the default DAC reference setting
//! of VDAC.
//!
//! When the DAC reference is set to VDAC, an external reference voltage
//! must be applied to the VDAC pin. This can accomplished by connecting a
//! jumper wire from 3.3V to ADCINB0 (HSEC pin 12).
//!
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
#include <time.h>
#include <stdlib.h>
#include "F28x_Project.h"

//
// Defines
//
#define REFERENCE_VDAC      0
#define REFERENCE_VREF      1
#define DACA                1
#define DACB                2
#define DACC                3
#define REFERENCE           REFERENCE_VDAC
#define DAC_NUM             DACA

//
// Globals
//
volatile struct DAC_REGS* DAC_PTR[4] = {0x0,&DacaRegs,&DacbRegs,&DaccRegs};
Uint16 low_limit = 410;
Uint16 high_limit = 3686;

//
// Function Prototypes
//
void configureDAC(Uint16 dac_num);

void main(void)
{
//
// Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the F2837xS_SysCtrl.c file.
//
    InitSysCtrl();

//
// Disable CPU interrupts
//
    DINT;

//
// Initialize the PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags are cleared.
// This function is found in the F2837xS_PieCtrl.c file.
//
    InitPieCtrl();

//
// Clear all interrupts and initialize PIE vector table:
//
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

//
// Initialize random seed
//
    srand(time(NULL));

//
// Configure DAC
//
    configureDAC(DAC_NUM);

    while(1)
    {
        DAC_PTR[DAC_NUM]->DACVALS.all = (rand() % (high_limit-low_limit)) +
                                        low_limit;
        DELAY_US(1);
    }
}

//
// configureDAC - Setup the DAC reference selection and enable specified DAC
//
void configureDAC(Uint16 dac_num)
{
    EALLOW;
    DAC_PTR[dac_num]->DACCTL.bit.DACREFSEL = REFERENCE;
    DAC_PTR[dac_num]->DACOUTEN.bit.DACOUTEN = 1;
    DAC_PTR[dac_num]->DACVALS.all = 0;
    DELAY_US(10); // Delay for buffered DAC to power up
    EDIS;
}

//
// End of file
//
