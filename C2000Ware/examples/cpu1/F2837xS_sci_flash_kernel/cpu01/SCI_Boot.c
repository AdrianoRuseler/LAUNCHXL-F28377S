//###########################################################################
//
// FILE:    SCI_Boot.c
//
// TITLE:   SCI Boot mode routines
//
// Functions:
//
//     Uint32 SCI_Boot(void)
//     inline void SCIA_Init(void)
//     inline void SCIA_AutobaudLock(void)
//     Uint32 SCIA_GetWordData(void)
//
// Notes:
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
#include "c1_bootrom.h"
#include "F2837xS_Gpio_defines.h"
#include "F2837xS_GlobalPrototypes.h"
#include "Types.h"

//
// Defines
//
#define NO_ERROR                    0x1000
#define BLANK_ERROR                 0x2000
#define VERIFY_ERROR                0x3000
#define PROGRAM_ERROR               0x4000
#define COMMAND_ERROR               0x5000

#define C1C2_BROM_IPC_EXECUTE_BOOTMODE_CMD    0x00000013
#define C1C2_BROM_BOOTMODE_BOOT_FROM_SCI      0x00000001
#define C1C2_BROM_BOOTMODE_BOOT_FROM_RAM      0x0000000A
#define C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH    0x0000000B

//
// Globals
//
typedef struct
{
   Uint16 status;
   Uint32 address;
}  StatusCode;
extern StatusCode statusCode;

//
// Function Prototypes (External)
//
extern Uint16 SCIA_GetWordData(void);
extern Uint32 CopyData(void);
Uint32 GetLongData(void);
extern void ReadReservedFn(void);
extern void Example_Error(Fapi_StatusType status);

//
// Function Prototypes (Local)
//
Uint32 SCI_Boot(Uint32 BootMode);

//
// Uint32 SCI_Boot - This module is the main SCI boot routine.
//                   It will load code via the SCI-A port.
//                   It will return a entry point address back
//                   to the InitBoot routine which in turn calls
//                   the ExitBoot routine.
//
Uint32 SCI_Boot(Uint32 BootMode)
{
    statusCode.status = NO_ERROR;
    statusCode.address = 0x12346578;

    Uint32 EntryAddr;

    //
    // Assign GetWordData to the SCI-A version of the
    // function. GetWordData is a pointer to a function.
    //
    GetWordData = SCIA_GetWordData;

    //
    // If the KeyValue was invalid, abort the load
    // and return the flash entry point.
    //
    if (SCIA_GetWordData() != 0x08AA)
    {
        statusCode.status = VERIFY_ERROR;
        statusCode.address = FLASH_ENTRY_POINT;
    }

    ReadReservedFn(); //reads and discards 8 reserved words

    EntryAddr = GetLongData();

    CopyData();

    Uint16 x = 0;
    for(x = 0; x < 32676; x++){}
    for(x = 0; x < 32676; x++){}

    return EntryAddr;
}

//
// End of file
//
