;//###########################################################################
;//
;// FILE:  F2837xS_DBGIER.asm
;//
;// TITLE: Set the DBGIER register
;//
;// DESCRIPTION:
;//
;//  Function to set the DBGIER register (for realtime emulation).
;//  Function Prototype: void SetDBGIER(Uint16)
;//  Usage: SetDBGIER(value);
;//  Input Parameters: Uint16 value = value to put in DBGIER register.
;//  Return Value: none
;//
;//###########################################################################
;// $TI Release: F2837xS Support Library v210 $
;// $Release Date: Tue Nov  1 15:35:23 CDT 2016 $
;// $Copyright: Copyright (C) 2014-2016 Texas Instruments Incorporated -
;//             http://www.ti.com/ ALL RIGHTS RESERVED $
;//###########################################################################
        .global _SetDBGIER
        .text

_SetDBGIER:
        MOV     *SP++,AL
        POP     DBGIER
        LRETR

;//
;// End of file
;//
