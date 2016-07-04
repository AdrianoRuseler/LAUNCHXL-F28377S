/*--------------------------------------------------------*/
/* Fapi_UserDefinedFunctions.c                            */
/*                                                        */
/* Copyright (c) 2009-2016 Texas Instruments Incorporated */
/*                                                        */
/* F021 Flash API v1.55                                   */
/*--------------------------------------------------------*/

/*!
    \file Fapi_UserDefinedFunctions.c
    \brief Contains all user defined functions that the Fapi functions use.
*/

/* Uncomment the appropriate include file for your device */

/*#include "F021_FMC_BE.h"*/
/*#include "F021_FMC_LE.h"*/
/*#include "F021_Concerto_C28x.h"*/
/*#include "F021_Concerto_Cortex.h"*/
/*#include "F021_F2837xD_C28x.h"&*/
#include "F021_F2837xS_C28x.h"

Fapi_StatusType Fapi_serviceWatchdogTimer(void)
{
   /* User to add their own watchdog servicing code here */

   return(Fapi_Status_Success);
}

/* End of File */

