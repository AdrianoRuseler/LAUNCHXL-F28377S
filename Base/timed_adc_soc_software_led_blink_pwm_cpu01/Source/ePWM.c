/*
 * ePWM.c
 */


//
// Included Files
//
#include "F28x_Project.h"
#include "ePWM.h"


extern EPWM_INFO epwm1_info;
extern EPWM_INFO epwm2_info;
extern EPWM_INFO epwm3_info;

//
// InitEPwmGpio - Initialize EPWM GPIOs
//
void InitEPwmGpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins
    //   for reduced power consumption
    // Pull-ups can be enabled or disabled by the user.
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up on GPIO3 (EPWM2B)
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // Disable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;    // Disable pull-up on GPIO5 (EPWM3B)

    //
    // Configure EPwm-3 pins using GPIO regs
    // This specifies which of the possible GPIO pins will be EPWM3 functional pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B

    EDIS;
}



//
// InitEPwm1Example - Initialize EPWM1 configuration
//
void InitEPwm1Example()
{
    //
    // Setup TBCLK
    //
    EPwm1Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period 801 TBCLKs
    EPwm1Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm1Regs.TBCTR = 0x0000;                  // Clear counter

    //
    // Set Compare values
    //
    EPwm1Regs.CMPA.bit.CMPA = EPWM1_MIN_CMPA;    // Set compare A value
    EPwm1Regs.CMPB.bit.CMPB = EPWM1_MAX_CMPB;    // Set Compare B value

    //
    // Setup counter mode
    //
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up and down
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    //
    // Setup shadowing
    //
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // Load on Zero
    EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    //
    // Set actions
    //
    EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;            // Set PWM1A on event A, up
                                                  // count
    EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;          // Clear PWM1A on event A,
                                                  // down count

    EPwm1Regs.AQCTLB.bit.CBU = AQ_SET;            // Set PWM1B on event B, up
                                                  // count
    EPwm1Regs.AQCTLB.bit.CBD = AQ_CLEAR;          // Clear PWM1B on event B,
                                                  // down count

    //
    // Interrupt where we will change the Compare Values
    //
    EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
    EPwm1Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm1Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

    //
    // Information this example uses to keep track
    // of the direction the CMPA/CMPB values are
    // moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm1_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA
    epwm1_info.EPwm_CMPB_Direction = EPWM_CMP_DOWN; // & decreasing CMPB
    epwm1_info.EPwmTimerIntCount = 0;               // Zero the interrupt counter
    epwm1_info.EPwmRegHandle = &EPwm1Regs;          // Set the pointer to the
                                                    // ePWM module
    epwm1_info.EPwmMaxCMPA = EPWM1_MAX_CMPA;        // Setup min/max CMPA/CMPB
                                                    // values
    epwm1_info.EPwmMinCMPA = EPWM1_MIN_CMPA;
    epwm1_info.EPwmMaxCMPB = EPWM1_MAX_CMPB;
    epwm1_info.EPwmMinCMPB = EPWM1_MIN_CMPB;
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







