/*--------------------------------------------------------*/
/* F021\Constants\Constants.h                             */
/*                                                        */
/* $Release Date: Fri Mar 11 15:58:35 CST 2016 $                                      */
/* $Copyright: Copyright (C) 2014-2016 Texas Instruments Incorporated -                                         */  
/*             http://www.ti.com/ ALL RIGHTS RESERVED $ */
/*                                                        */
/* F021 Flash API v1.55                                   */
/*--------------------------------------------------------*/

/*!
    \file F021\Constants\Constants.h
    \brief A set of Constant Values.
*/
#ifndef F021_CONSTANTS_H_
#define F021_CONSTANTS_H_

#if defined(_CONCERTO)
    #include "Concerto.h"
#elif defined(_F2837xD)
    #include "F2837xD.h"
#elif defined(_F2837xS)
    #include "F2837xS.h"	
#elif defined(_F28004x)
    #include "F28004x.h"	
#else
    #include "FMC.h"
#endif


#if defined (_F2837xS)
	/*!
		\brief Define to map the direct access to the TI OTP memory.
	*/
	#define F021_TIOTP1_BASE_ADDRESS ((Fapi_TiOtpBytesType *)(F021_PROGRAM_TIOTP1_OFFSET + F021_TIOTP_SETTINGS_BASE))
	#define F021_TIOTP2_BASE_ADDRESS ((Fapi_TiOtpBytesType *)(F021_PROGRAM_TIOTP2_OFFSET + F021_TIOTP_SETTINGS_BASE))
	#define F021_TIOTP_BASE_ADDRESS ((Fapi_TiOtpBytesType *)(F021_PROGRAM_TIOTP_OFFSET + F021_TIOTP_SETTINGS_BASE))
	
	/*!
		\brief Define to map the direct access to the FMC registers.
	*/
	#define F021_CPU0_W0_BASE_ADDRESS ((Fapi_FmcRegistersType *)F021_CPU0_W0_REGISTER_ADDRESS)
	#define F021_CPU0_W1_BASE_ADDRESS ((Fapi_FmcRegistersType *)F021_CPU0_W1_REGISTER_ADDRESS)

#else
/*!
		\brief Define to map the direct access to the TI OTP memory.
	*/
	#define F021_TIOTP_BASE_ADDRESS ((Fapi_TiOtpBytesType *)(F021_PROGRAM_TIOTP_OFFSET + F021_TIOTP_SETTINGS_BASE))

	/*!
		\brief Define to map the direct access to the FMC registers.
	*/
	#define F021_CPU0_BASE_ADDRESS ((Fapi_FmcRegistersType *)F021_CPU0_REGISTER_ADDRESS)
	
#endif

#endif /* F021_CONSTANTS_H_ */
