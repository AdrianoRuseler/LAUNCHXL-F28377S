//###########################################################################
//
// FILE:   interrupt.h
//
// TITLE:  Stellaris style wrapper driver for C28x PIE Interrupt Controller.
//
//###########################################################################
// $TI Release: F2837xS Support Library v191 $
// $Release Date: Fri Mar 11 15:58:35 CST 2016 $
// $Copyright: Copyright (C) 2014-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
    extern bool IntMasterEnable(void);
    extern bool IntMasterDisable(void);
    extern void IntRegister(uint32_t ui32Interrupt, void (*pfnHandler)(void));
    extern void IntUnregister(uint32_t ui32Interrupt);
    extern void IntEnable(uint32_t ui32Interrupt);
    extern void IntDisable(uint32_t ui32Interrupt);
    extern void IntIFRClear(uint16_t ui16Interrupts);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __INTERRUPT_H__


