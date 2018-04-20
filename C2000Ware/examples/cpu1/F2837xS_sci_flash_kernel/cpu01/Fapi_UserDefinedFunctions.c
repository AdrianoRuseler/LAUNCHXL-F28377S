//###########################################################################
//
// FILE:   Fapi_UserDefinedFunctions.c
//
// TITLE:  F021 Flash API v1.55
//
//###########################################################################
// $TI Release: F2837xS Support Library v3.04.00.00 $
// $Release Date: Sun Mar 25 13:27:27 CDT 2018 $
// $Copyright:
// Copyright (C) 2014-2017 Texas Instruments Incorporated - http://www.ti.com/
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

/*!
    \file Fapi_UserDefinedFunctions.c
    \brief Contains all user defined functions that the Fapi functions use.
*/

//
// Uncomment the appropriate include file for your device
//

//#include "F021_FMC_BE.h"
//#include "F021_FMC_LE.h"
//#include "F021_Concerto_C28x.h"
//#include "F021_Concerto_Cortex.h"
//#include "F021_F2837xD_C28x.h"
#include "F021_F2837xS_C28x.h"

#ifdef __TI_COMPILER_VERSION__
    #if __TI_COMPILER_VERSION__ >= 15009000 
        #define ramFuncSection ".TI.ramfunc"
    #else
        #define ramFuncSection "ramfuncs"
    #endif
#endif

//
// Fapi_serviceWatchdogTimer - Service Watchdog timer
//
#pragma CODE_SECTION(Fapi_serviceWatchdogTimer,ramFuncSection);
Fapi_StatusType Fapi_serviceWatchdogTimer(void)
{
   //
   // User to add their own watchdog servicing code here
   //

   return(Fapi_Status_Success);
}

//
// End of file
//

