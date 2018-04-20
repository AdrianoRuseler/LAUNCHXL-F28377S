//###########################################################################
//
// FILE:   F2837x_sci_flash_kernels.c
//
// TITLE:  Flash Programming Solution using SCI for F2837xS.
//
//! \addtogroup cpu01_example_list
//! <h1>Flash Programming Solution SCI for F2837xS</h1>
//!
//! In this example, we set up a UART connection with a host using SCI, receive
//! commands for CPU1 to perform which then sends ACK, NAK, and status packets
//! back to the host after receiving and completing the tasks. Each command
//! either expects no data from the command packet or specific data relative
//! to the command.
//!
//! In this example, we set up a UART connection with a host using SCI, receive
//! an application for CPU01 in -sci8 ascii format to run on the device and
//! program it into Flash.
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
#include "Shared_Erase.h"
#include <string.h>
#include "flash_programming_c28.h" //Flash API example header file
#include "c1_bootrom.h"
#include "F021_F2837xS_C28x.h"

//
// Defines
//
#define C1C2_BROM_IPC_EXECUTE_BOOTMODE_CMD    0x00000013
#define C1C2_BROM_BOOTMODE_BOOT_FROM_SCI      0x00000001
#define C1C2_BROM_BOOTMODE_BOOT_FROM_RAM      0x0000000A
#define C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH    0x0000000B

//
// Function Prototypes
//
void Example_Error(Fapi_StatusType status);
void Init_Flash_Sectors(void);
extern Uint32 SCI_GetFunction(Uint32  BootMode);

//
// main - This is an example code demonstrating F021 Flash API usage.
//        This code is in Flash
//
uint32_t main(void)
{
//
// SCIA Flush
//
    while(!SciaRegs.SCICTL2.bit.TXEMPTY)
    {
    }

//
// Step 1. Initialize System Control:
// Enable Peripheral Clocks
// This example function is found in the F2837xS_SysCtrl.c file.
//
    InitSysCtrl(); //PLL activates

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
//    InitPieCtrl();

//
// Disable CPU interrupts and clear all CPU interrupt flags:
//
    IER = 0x0000;
    IFR = 0x0000;

    //
    // Initialize the Flash.
    //
    InitFlash_Bank1();
    InitFlash_Bank0();
    Init_Flash_Sectors();

    //
    // Gain pump semaphore for Bank0.
    // User may need to do this for Bank1 if programming Bank1.
    //
    SeizeFlashPump_Bank0();

    Uint32 EntryAddr;

//
// parameter SCI_BOOT for GPIO84,85; parameter SCI_BOOT_ALTERNATE for
// GPIO28,29
//
    EntryAddr = SCI_GetFunction(SCI_BOOT_ALTERNATE);

    return(EntryAddr);
}

//
// Init_Flash_Sectors - Initialize flash sectors
//
void Init_Flash_Sectors(void)
{
    EALLOW;
    Flash0EccRegs.ECC_ENABLE.bit.ENABLE = 0x0;
    Flash1EccRegs.ECC_ENABLE.bit.ENABLE = 0x0;

    Fapi_StatusType oReturnCheck;
    oReturnCheck = Fapi_initializeAPI(F021_CPU0_W0_BASE_ADDRESS, 150);
    if(oReturnCheck != Fapi_Status_Success)
    {
        Example_Error(oReturnCheck);
    }
    oReturnCheck = Fapi_initializeAPI(F021_CPU0_W1_BASE_ADDRESS, 150);
    if(oReturnCheck != Fapi_Status_Success)
    {
        Example_Error(oReturnCheck);
    }

    oReturnCheck = Fapi_setActiveFlashBank(Fapi_FlashBank0);
    if(oReturnCheck != Fapi_Status_Success)
    {
        Example_Error(oReturnCheck);
    }
    oReturnCheck = Fapi_setActiveFlashBank(Fapi_FlashBank1);
    if(oReturnCheck != Fapi_Status_Success)
    {
        Example_Error(oReturnCheck);
    }

    Flash0EccRegs.ECC_ENABLE.bit.ENABLE = 0xA;
    Flash1EccRegs.ECC_ENABLE.bit.ENABLE = 0xA;
    EDIS;
}

//
// Example_Error - Error function that will halt debugger
//
#pragma CODE_SECTION(Example_Error,".TI.ramfunc");
void Example_Error(Fapi_StatusType status)
{
    //
    // Error code will be in the status parameter
    //
    __asm("    ESTOP0");
}

//
// End of file
//
