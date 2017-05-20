/*
//###########################################################################
// FILE:    flash_programming_cpu1_FLASH.cmd
// TITLE:   Linker Command File For all F28X7x devices
//###########################################################################
// $TI Release: F2837xS Support Library v210 $
// $Release Date: Tue Nov  1 15:35:23 CDT 2016 $
// $Copyright: Copyright (C) 2014-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################
*/

/* ======================================================
// For Code Composer Studio V2.2 and later
// ---------------------------------------
// In addition to this memory linker command file,
// add the header linker command file directly to the project.
// The header linker command file is required to link the
// peripheral structures to the proper locations within
// the memory map.
// The header linker files are found in <base>\F2837xS_headers\cmd
// For BIOS applications add:      F28X7x_Headers_BIOS.cmd
// For nonBIOS applications add:   F28X7x_Headers_nonBIOS.cmd
========================================================= */

/* Define the memory block start/length for the F28X7x
   PAGE 0 will be used to organize program sections
   PAGE 1 will be used to organize data sections

   Notes:
         Memory blocks on F28M3Xx are uniform (ie same
         physical memory) in both PAGE 0 and PAGE 1.
         That is the same memory region should not be
         defined for both PAGE 0 and PAGE 1.
         Doing so will result in corruption of program
         and/or data.

         Contiguous SARAM memory blocks or flash sectors can be
         be combined if required to create a larger memory block.
*/

MEMORY
{
PAGE 0:    /* Program Memory */
          /* Memory (RAM/FLASH) blocks can be moved to PAGE1 for data allocation */
          /* BEGIN is used for the "boot to Flash" bootloader mode   */

   BEGIN           	: origin = 0x080000, length = 0x000002
   RAMM0           	: origin = 0x000122, length = 0x0002DE
   RAMD0           	: origin = 0x00B000, length = 0x000800
   RAMLS03          : origin = 0x008000, length = 0x002000
/*	RAMLS1           : origin = 0x008800, length = 0x000800
    RAMLS2           : origin = 0x009000, length = 0x000800
    RAMLS3           : origin = 0x009800, length = 0x000800 */
   RAMLS4      		: origin = 0x00A000, length = 0x000800
   RESET           	: origin = 0x3FFFC0, length = 0x000002
  
	/* Flash sectors */
   FLASHA           : origin = 0x080002, length = 0x001FFE	/* on-chip Flash */
   FLASHB           : origin = 0x082000, length = 0x002000	/* on-chip Flash */
   FLASHC           : origin = 0x084000, length = 0x002000	/* on-chip Flash */
   FLASHD           : origin = 0x086000, length = 0x002000	/* on-chip Flash */
   FLASHE           : origin = 0x088000, length = 0x008000	/* on-chip Flash */
   FLASHF           : origin = 0x090000, length = 0x008000	/* on-chip Flash */
   FLASHG           : origin = 0x098000, length = 0x008000	/* on-chip Flash */
   FLASHH           : origin = 0x0A0000, length = 0x008000	/* on-chip Flash */
   FLASHI           : origin = 0x0A8000, length = 0x008000	/* on-chip Flash */
   FLASHJ           : origin = 0x0B0000, length = 0x008000	/* on-chip Flash */
   FLASHK           : origin = 0x0B8000, length = 0x002000	/* on-chip Flash */
   FLASHL           : origin = 0x0BA000, length = 0x002000	/* on-chip Flash */
   FLASHM           : origin = 0x0BC000, length = 0x002000	/* on-chip Flash */
   FLASHN           : origin = 0x0BE000, length = 0x002000	/* on-chip Flash */

PAGE 1 :   /* Data Memory */
         /* Memory (RAM/FLASH) blocks can be moved to PAGE0 for program allocation */

    BOOT_RSVD       : origin = 0x000002, length = 0x000120     /* Part of M0, BOOT rom will use this for stack */
	RAMM1           : origin = 0x000400, length = 0x000400     /* on-chip RAM block M1 */
    RAMD1           : origin = 0x00B800, length = 0x000800

    RAMLS5      : origin = 0x00A800, length = 0x000800

	RAMGS0          : origin = 0x00C000, length = 0x001000
	RAMGS1          : origin = 0x00D000, length = 0x001000
	RAMGS2          : origin = 0x00E000, length = 0x001000
	RAMGS3          : origin = 0x00F000, length = 0x001000
	RAMGS4          : origin = 0x010000, length = 0x001000
	RAMGS5          : origin = 0x011000, length = 0x001000
	RAMGS6          : origin = 0x012000, length = 0x001000
	RAMGS7          : origin = 0x013000, length = 0x001000
}


SECTIONS
{

   /* Allocate program areas: */
   .cinit              : > FLASHD      PAGE = 0
   .pinit              : > FLASHD,     PAGE = 0
   .text               : >> FLASHD | FLASHE      PAGE = 0
   codestart           : > BEGIN	PAGE = 0

#ifdef __TI_COMPILER_VERSION__
    #if __TI_COMPILER_VERSION__ >= 15009000
        GROUP
        {
            .TI.ramfunc
            { -l F021_API_F2837xS_FPU32.lib}
         
        } LOAD = FLASHD,
          RUN  = RAMLS03, 
          LOAD_START(_RamfuncsLoadStart),
          LOAD_SIZE(_RamfuncsLoadSize),
          LOAD_END(_RamfuncsLoadEnd),
          RUN_START(_RamfuncsRunStart),
          RUN_SIZE(_RamfuncsRunSize),
          RUN_END(_RamfuncsRunEnd),
          PAGE = 0    
    #else
        GROUP
        {
            ramfuncs
            { -l F021_API_F2837xS_FPU32.lib}
         
        } LOAD = FLASHD,
          RUN  = RAMLS03, 
          LOAD_START(_RamfuncsLoadStart),
          LOAD_SIZE(_RamfuncsLoadSize),
          LOAD_END(_RamfuncsLoadEnd),
          RUN_START(_RamfuncsRunStart),
          RUN_SIZE(_RamfuncsRunSize),
          RUN_END(_RamfuncsRunEnd),
          PAGE = 0    
    #endif
#endif
   


   /* Allocate uninitalized data sections: */
   .stack              : > RAMM1       PAGE = 1
   .ebss               : >> RAMLS5 | RAMGS0 | RAMGS1       PAGE = 1
   .esysmem            : > RAMLS5       PAGE = 1

   /* Initalized sections go in Flash */
   .econst             : >> FLASHF | FLASHG       PAGE = 0
   .switch             : > FLASHD      PAGE = 0

   .reset              : > RESET,     PAGE = 0, TYPE = DSECT /* not used, */

   Filter_RegsFile     : > RAMGS0,	   PAGE = 1

   SHARERAMGS0		: > RAMGS0,		PAGE = 1
   SHARERAMGS1		: > RAMGS1,		PAGE = 1

   /* Flash Programming Buffer */
   BufferDataSection : > RAMD1, PAGE = 1, ALIGN(4)  
   
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/




