//###########################################################################
// FILE:   flash_programming_cpu01.c
// TITLE:  Flash Programming Example for F2837xS.
//
//! \addtogroup cpu01_example_list
//! <h1> Flash Programming </h1>
//!
//! This example demonstrates F021 Flash API usage to program
//! Flash Bank0 and Bank1 on F2837xS.
//!
//! \b Important: The Bank1 code is only applicable for devices that have the
//!               second bank. Check the data manual to determine if your
//!               device part number is compatible.
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
#include "F28x_Project.h"
#include <string.h>
#include "flash_programming_c28.h"      // Flash API example header file
#include "F021_F2837xS_C28x.h"

//
// Defines
//
#define  WORDS_IN_FLASH_BUFFER    0xFF  // Programming data buffer, words
#define PUMPREQUEST *(unsigned long*)(0x00050024)

#ifdef __TI_COMPILER_VERSION__
    #if __TI_COMPILER_VERSION__ >= 15009000 
        #define ramFuncSection ".TI.ramfunc"
    #else
        #define ramFuncSection "ramfuncs"
    #endif
#endif

//
// Globals
//
#pragma DATA_SECTION(Buffer,"BufferDataSection");
uint16   Buffer[WORDS_IN_FLASH_BUFFER + 1];
uint32   *Buffer32 = (uint32 *)Buffer;

//
// Function Prototypes
//
void Example_Error(Fapi_StatusType status);
void Example_Done(void);
void Example_CallFlashAPI(void);

//
// Main
//
void main(void)
{
//
// Step 1. Initialize System Control:
// Enable Peripheral Clocks
// This example function is found in the F2837xS_SysCtrl.c file.
//
    InitSysCtrl();

//
//  Unlock CSM
//
//  If the API functions are going to run in unsecured RAM
//  then the CSM must be unlocked in order for the flash
//  API functions to access the flash.
//  If the flash API functions are executed from secure memory
//  then this step is not required.
//
    //DcsmZ1Unlock();

//
// Step 2. Initialize GPIO:
// This example function is found in the F2837xS_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
//
// InitGpio();  // Skipped for this example

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
// Copy time critical code and Flash setup code to RAM
// This includes InitFlash_Bank0(), Flash API functions and any functions that are
// assigned to ramfuncs section.
// The  RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
// symbols are created by the linker. Refer to the device .cmd file.
//
   //memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

//
// Call Flash Initialization to setup flash waitstates
// This function must reside in RAM
//
    InitFlash_Bank0();
    InitFlash_Bank1();

//
// Jump to RAM and call the Flash API functions
//
    Example_CallFlashAPI();
}

//
// Example_CallFlashAPI - This function will interface to the flash API.
//                        Flash API functions used in this function are
//                        executed from RAM.
//
#pragma CODE_SECTION(Example_CallFlashAPI, ramFuncSection);
void Example_CallFlashAPI(void)
{
    uint32 u32Index = 0;
    uint16 i = 0;

    Fapi_StatusType oReturnCheck;
    volatile Fapi_FlashStatusType oFlashStatus;
    Fapi_FlashStatusWordType oFlashStatusWord;

    //
    // Bank0 Erase Program
    //
    EALLOW;

    //
    //Give pump ownership to FMC0
    //
    PUMPREQUEST = 0x5A5A0002;

    //
    // This function is required to initialize the Flash API based on System
    // frequency before any other Flash API operation can be performed
    // Note that the FMC0 register base address is passed as the parameter
    //
    oReturnCheck = Fapi_initializeAPI(F021_CPU0_W0_BASE_ADDRESS, 194);

    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        //
        Example_Error(oReturnCheck);
    }

    //
    // Fapi_setActiveFlashBank function sets the Flash bank0 and FMC0 for
    // further Flash operations to be performed on the bank0.
    // Note that the parameter passed is Fapi_FlashBank0 since FMC0 register
    // base address is passed to Fapi_initializeAPI()
    //
    oReturnCheck = Fapi_setActiveFlashBank(Fapi_FlashBank0);
    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        //
        Example_Error(oReturnCheck);
    }

    //
    // Erase Sector C
    //
    oReturnCheck = Fapi_issueAsyncCommandWithAddress(Fapi_EraseSector,
                                                (uint32 *)Bzero_SectorC_start);

    //
    // Wait until FSM is done with erase sector operation
    //
    while(Fapi_checkFsmForReady() != Fapi_Status_FsmReady){}

    //
    // Verify that SectorL is erased.  The Erase step itself does a
    // verify as it goes.  This verify is a 2nd verification that can be done.
    //
    oReturnCheck = Fapi_doBlankCheck((uint32 *)Bzero_SectorC_start,
                                     Bzero_16KSector_u32length,
                                     &oFlashStatusWord);

    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        // If Erase command fails, use Fapi_getFsmStatus() function to get the
        // FMSTAT register contents to see if any of the EV bit, ESUSP bit,
        // CSTAT bit or VOLTSTAT bit is set (Refer to API documentation for
        // more details)
        //
        Example_Error(oReturnCheck);
    }

    //
    // A data buffer of max 8 words can be supplied to the program function.
    // Each word is programmed until the whole buffer is programmed or a
    // problem is found. However to program a buffer that has more than 8
    // words, program function can be called in a loop to program 8 words for
    // each loop iteration until the whole buffer is programmed
    //

    //
    // Example: Program 0xFF bytes in Flash Sector C along with auto-
    // generated ECC
    //

    //
    // In this case just fill a buffer with data to program into the flash.
    //
    for(i=0; i<=WORDS_IN_FLASH_BUFFER; i++)
    {
        Buffer[i] = i;
    }

    for(i=0, u32Index = Bzero_SectorC_start;
        (u32Index < (Bzero_SectorC_start + WORDS_IN_FLASH_BUFFER)) &&
        (oReturnCheck == Fapi_Status_Success); i+= 8, u32Index+= 8)
    {
        oReturnCheck = Fapi_issueProgrammingCommand((uint32 *)u32Index,Buffer+i,
                                                    8,0,0,
                                                    Fapi_AutoEccGeneration);

        while(Fapi_checkFsmForReady() == Fapi_Status_FsmBusy);

        if(oReturnCheck != Fapi_Status_Success)
        {
            //
            // Check Flash API documentation for possible errors
            //
            Example_Error(oReturnCheck);
        }

        //
        // Read FMSTAT register contents to know the status of FSM after
        // program command for any debug
        //
        oFlashStatus = Fapi_getFsmStatus();

        //
        // Verify the values programmed.  The Program step itself does a verify
        // as it goes.  This verify is a 2nd verification that can be done.
        //
        oReturnCheck = Fapi_doVerify((uint32 *)u32Index,4,Buffer32+(i/2),
                                     &oFlashStatusWord);

        if(oReturnCheck != Fapi_Status_Success)
        {
            //
            // Check Flash API documentation for possible errors
            //
            Example_Error(oReturnCheck);
        }
    }

    //
    // Erase the sectors that we have programmed above
    // Erase Sector C
    //
    oReturnCheck = Fapi_issueAsyncCommandWithAddress(Fapi_EraseSector,
                                                (uint32 *)Bzero_SectorC_start);

    //
    // Wait until FSM is done with erase sector operation
    //
    while(Fapi_checkFsmForReady() != Fapi_Status_FsmReady){}

    //
    // Verify that SectorC is erased.  The Erase step itself does a verify as
    // it goes.
    // This verify is a 2nd verification that can be done.
    //
    oReturnCheck = Fapi_doBlankCheck((uint32 *)Bzero_SectorC_start,
                                     Bzero_16KSector_u32length,
                                     &oFlashStatusWord);

    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        // If Erase command fails, use Fapi_getFsmStatus() function to get the
        // FMSTAT register contents
        // to see if any of the EV bit, ESUSP bit, CSTAT bit or VOLTSTAT bit is
        // set (Refer to API documentation for more details)
        //
        Example_Error(oReturnCheck);
    }

    //
    // Bank1 Erase Program
    //

    //
    // Give pump ownership to FMC1
    //
    PUMPREQUEST = 0x5A5A0001;

    //
    // This function is required to initialize the Flash API based on System
    // frequency before any other Flash API operation can be performed
    // Note that the FMC1 register base address is passed as the parameter
    //
    oReturnCheck = Fapi_initializeAPI(F021_CPU0_W1_BASE_ADDRESS, 200);

    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        //
        Example_Error(oReturnCheck);
    }

    //
    // Fapi_setActiveFlashBank function sets the Flash bank1 and FMC1 for
    // further Flash operations to be performed on the bank1.
    // Note that the parameter passed is Fapi_FlashBank1 since FMC0 register
    // base address is passed to Fapi_initializeAPI()
    //
    oReturnCheck = Fapi_setActiveFlashBank(Fapi_FlashBank1);
    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        //
        Example_Error(oReturnCheck);
    }

    //
    // Erase Sector P
    //
    oReturnCheck = Fapi_issueAsyncCommandWithAddress(Fapi_EraseSector,
                                                 (uint32 *)BOne_SectorP_start);

    //
    // Wait until FSM is done with erase sector operation
    //
    while (Fapi_checkFsmForReady() != Fapi_Status_FsmReady){}

    //
    // Verify that SectorP is erased.  The Erase step itself does a verify as
    // it goes.  This verify is a 2nd verification that can be done.
    //
    oReturnCheck = Fapi_doBlankCheck((uint32 *)BOne_SectorP_start,
                                     BOne_16KSector_u32length,
                                     &oFlashStatusWord);

    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        // If Erase command fails, use Fapi_getFsmStatus() function
        // to get the FMSTAT register contents
        // to see if any of the EV bit, ESUSP bit, CSTAT bit or VOLTSTAT
        // bit is set (Refer to API documentation for more details)
        //
        Example_Error(oReturnCheck);
    }

    //
    // Example:  Program 0xFF bytes in Flash Sector P with out ECC
    // Disable ECC so that error is not generated when reading Flash contents
    // without ECC
    //
    Flash1EccRegs.ECC_ENABLE.bit.ENABLE = 0x0;

    for(i=0, u32Index = BOne_SectorP_start;
        (u32Index < (BOne_SectorP_start + WORDS_IN_FLASH_BUFFER)) &&
        (oReturnCheck == Fapi_Status_Success); i+= 8, u32Index+= 8)
    {
        oReturnCheck = Fapi_issueProgrammingCommand((uint32 *)u32Index,
                                                    Buffer+i,8,0,0,
                                                    Fapi_DataOnly);

        while(Fapi_checkFsmForReady() == Fapi_Status_FsmBusy);

        if(oReturnCheck != Fapi_Status_Success)
        {
            //
            // Check Flash API documentation for possible errors
            //
            Example_Error(oReturnCheck);
        }

        //
        // Read FMSTAT register contents to know the status of FSM
        // after program command for any debug
        //
        oFlashStatus = Fapi_getFsmStatus();

        //
        // Verify the values programmed.  The Program step itself does a verify
        // as it goes.  This verify is a 2nd verification that can be done.
        //
        oReturnCheck = Fapi_doVerify((uint32 *)u32Index,4,Buffer32+(i/2),
                                     &oFlashStatusWord);

        if(oReturnCheck != Fapi_Status_Success)
        {
            //
            // Check Flash API documentation for possible errors
            //
            Example_Error(oReturnCheck);
        }
    }

    //
    // Erase Sector P
    //
    oReturnCheck = Fapi_issueAsyncCommandWithAddress(Fapi_EraseSector,
                                                 (uint32 *)BOne_SectorP_start);

    //
    // Wait until FSM is done with erase sector operation
    //
    while (Fapi_checkFsmForReady() != Fapi_Status_FsmReady){}

    //
    // Verify that SectorP is erased.  The Erase step itself does a verify as
    // it goes.  This verify is a 2nd verification that can be done.
    //
    oReturnCheck = Fapi_doBlankCheck((uint32 *)BOne_SectorP_start,
                                     BOne_16KSector_u32length,
                                     &oFlashStatusWord);

    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        // If Erase command fails, use Fapi_getFsmStatus() function
        // to get the FMSTAT register contents
        // to see if any of the EV bit, ESUSP bit, CSTAT bit or VOLTSTAT
        // bit is set (Refer to API documentation for more details)
        //
        Example_Error(oReturnCheck);
    }

    //
    // Enable ECC
    //
    Flash1EccRegs.ECC_ENABLE.bit.ENABLE = 0xA;

    //
    // Give pump ownership back to FMC0
    //
    PUMPREQUEST = 0x5A5A0000;

    EDIS;

    //
    // Example is done here
    //
    Example_Done();
}

//
// Example_Error - For this example, if an error is found just stop here
//
#pragma CODE_SECTION(Example_Error,ramFuncSection);
void Example_Error(Fapi_StatusType status)
{
    //
    //  Error code will be in the status parameter
    //
    __asm("    ESTOP0");
}

//
// Example_Done - For this example, once we are done just stop here
//
#pragma CODE_SECTION(Example_Done,ramFuncSection);
void Example_Done(void)
{
    __asm("    ESTOP0");
}

//
// End of file
//
