################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/cmd/2837xS_Generic_FLASH_lnk.cmd \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_headers/cmd/F2837xS_Headers_nonBIOS.cmd 

ASM_SRCS += \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_CodeStartBranch.asm \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_usDelay.asm 

C_SRCS += \
../Example_F28377xLaunchPadDemo.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_Adc.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_CpuTimers.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_DefaultISR.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_headers/source/F2837xS_GlobalVariableDefs.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_Gpio.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_PieCtrl.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_PieVect.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_Sci.c \
C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_SysCtrl.c \
../sci_io.c 

C_DEPS += \
./Example_F28377xLaunchPadDemo.d \
./F2837xS_Adc.d \
./F2837xS_CpuTimers.d \
./F2837xS_DefaultISR.d \
./F2837xS_GlobalVariableDefs.d \
./F2837xS_Gpio.d \
./F2837xS_PieCtrl.d \
./F2837xS_PieVect.d \
./F2837xS_Sci.d \
./F2837xS_SysCtrl.d \
./sci_io.d 

OBJS += \
./Example_F28377xLaunchPadDemo.obj \
./F2837xS_Adc.obj \
./F2837xS_CodeStartBranch.obj \
./F2837xS_CpuTimers.obj \
./F2837xS_DefaultISR.obj \
./F2837xS_GlobalVariableDefs.obj \
./F2837xS_Gpio.obj \
./F2837xS_PieCtrl.obj \
./F2837xS_PieVect.obj \
./F2837xS_Sci.obj \
./F2837xS_SysCtrl.obj \
./F2837xS_usDelay.obj \
./sci_io.obj 

ASM_DEPS += \
./F2837xS_CodeStartBranch.d \
./F2837xS_usDelay.d 

OBJS__QUOTED += \
"Example_F28377xLaunchPadDemo.obj" \
"F2837xS_Adc.obj" \
"F2837xS_CodeStartBranch.obj" \
"F2837xS_CpuTimers.obj" \
"F2837xS_DefaultISR.obj" \
"F2837xS_GlobalVariableDefs.obj" \
"F2837xS_Gpio.obj" \
"F2837xS_PieCtrl.obj" \
"F2837xS_PieVect.obj" \
"F2837xS_Sci.obj" \
"F2837xS_SysCtrl.obj" \
"F2837xS_usDelay.obj" \
"sci_io.obj" 

C_DEPS__QUOTED += \
"Example_F28377xLaunchPadDemo.d" \
"F2837xS_Adc.d" \
"F2837xS_CpuTimers.d" \
"F2837xS_DefaultISR.d" \
"F2837xS_GlobalVariableDefs.d" \
"F2837xS_Gpio.d" \
"F2837xS_PieCtrl.d" \
"F2837xS_PieVect.d" \
"F2837xS_Sci.d" \
"F2837xS_SysCtrl.d" \
"sci_io.d" 

ASM_DEPS__QUOTED += \
"F2837xS_CodeStartBranch.d" \
"F2837xS_usDelay.d" 

C_SRCS__QUOTED += \
"../Example_F28377xLaunchPadDemo.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_Adc.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_CpuTimers.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_DefaultISR.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_headers/source/F2837xS_GlobalVariableDefs.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_Gpio.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_PieCtrl.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_PieVect.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_Sci.c" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_SysCtrl.c" \
"../sci_io.c" 

ASM_SRCS__QUOTED += \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_CodeStartBranch.asm" \
"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/source/F2837xS_usDelay.asm" 


