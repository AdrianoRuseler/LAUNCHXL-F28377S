/*
 * ISR.c
 */

//
// Included Files
//
#include "F28x_Project.h"
#include "ePWM.h"

extern EPWM_INFO epwm1_info;
extern EPWM_INFO epwm2_info;
extern EPWM_INFO epwm3_info;


extern void update_compare(EPWM_INFO*);

//
// epwm1_isr - EPWM1 ISR
//
__interrupt void epwm1_isr(void)
{
    //
    // Update the CMPA and CMPB values
    //
    update_compare(&epwm1_info);

    //
    // Clear INT flag for this timer
    //
    EPwm1Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
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
// epwm3_isr - EPWM3 ISR
//
__interrupt void epwm3_isr(void)
{
    //
    // Update the CMPA and CMPB values
    //
    update_compare(&epwm3_info);

    //
    // Clear INT flag for this timer
    //
    EPwm3Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}



