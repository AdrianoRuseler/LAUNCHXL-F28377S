//###########################################################################
//
// FILE:	Example_EpwmSetup.c
//
// TITLE:	Pos speed measurement using EQEP peripheral
//
// DESCRIPTION:
//
// This file contains source for the ePWM initialization for the 
// pos/speed module
//
//###########################################################################
// $TI Release: F2837xS Support Library v191 $
// $Release Date: Fri Mar 11 15:58:35 CST 2016 $
// $Copyright: Copyright (C) 2014-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "Example_posspeed.h"   // Example specific Include file

#define TB_CLK   100e6

#define PWM_CLK   5e3              // 5kHz (300rpm) EPWM1 frequency. Freq. can be changed here
#define SP        TB_CLK/(2*PWM_CLK)
#define TBCTLVAL  0x200A           // up-down count, timebase=SYSCLKOUT

void initEpwm()
{
	EPwm1Regs.TBSTS.all=0;
	EPwm1Regs.TBPHS.all =0;
	EPwm1Regs.TBCTR=0;

	EPwm1Regs.CMPCTL.all=0x50;     // immediate mode for CMPA and CMPB   
	EPwm1Regs.CMPA.bit.CMPA=SP/2;
	EPwm1Regs.CMPB.all=0;
	
	EPwm1Regs.AQCTLA.all=0x60;     // CTR=CMPA when inc->EPWM1A=1, when dec->EPWM1A=0
	EPwm1Regs.AQCTLB.all=0x09;     // CTR=PRD ->EPWM1B=1, CTR=0 ->EPWM1B=0  
	EPwm1Regs.AQSFRC.all=0;
	EPwm1Regs.AQCSFRC.all=0;
	
	EPwm1Regs.TZSEL.all=0;
	EPwm1Regs.TZCTL.all=0;
	EPwm1Regs.TZEINT.all=0;
	EPwm1Regs.TZFLG.all=0;
	EPwm1Regs.TZCLR.all=0;
	EPwm1Regs.TZFRC.all=0;

	EPwm1Regs.ETSEL.all=0x0A;      // Interrupt on PRD 
	EPwm1Regs.ETPS.all=1;	
	EPwm1Regs.ETFLG.all=0;
	EPwm1Regs.ETCLR.all=0;
	EPwm1Regs.ETFRC.all=0;
	
	EPwm1Regs.PCCTL.all=0;
	
	EPwm1Regs.TBCTL.all=0x0010+TBCTLVAL; // Enable Timer
	EPwm1Regs.TBPRD=SP;
}

