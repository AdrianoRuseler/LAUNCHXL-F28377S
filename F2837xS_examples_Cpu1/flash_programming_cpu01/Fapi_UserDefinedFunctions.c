//###########################################################################
//
// FILE:   Fapi_UserDefinedFunctions.c
//
// TITLE:  F021 Flash API v1.55
//
//###########################################################################
// $TI Release: F2837xS Support Library v210 $
// $Release Date: Tue Nov  1 15:35:23 CDT 2016 $
// $Copyright: Copyright (C) 2014-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
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

