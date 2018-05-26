//###########################################################################
//
// FILE:   stdafx.h
//
// TITLE:  include file for standard system include files
//
//###########################################################################
// $TI Release: F2837xS Support Library v210 $
// $Release Date: Tue Nov  1 15:35:23 CDT 2016 $
// $Copyright: Copyright (C) 2014-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers
#endif

//
// Modify the following defines if you have to target a platform prior to the
// ones specified below. Refer to MSDN for the latest info on corresponding
// values for different platforms.
#ifndef WINVER        // Allow use of features specific to Windows XP or later.
#define WINVER 0x0501        // Change this to the appropriate value to target
                             // other versions of Windows.
#endif

#ifndef _WIN32_WINNT  // Allow use of features specific to Windows XP or later.
#define _WIN32_WINNT 0x0501    // Change this to the appropriate value to target
                               // other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS // Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target
                              // Windows Me or later.
#endif

#ifndef _WIN32_IE         // Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600    // Change this to the appropriate value to target
                            // other versions of IE.
#endif

//
// some CString constructors will be explicit
//
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>            // MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>            // MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>    // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>            // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//
// End of file
//