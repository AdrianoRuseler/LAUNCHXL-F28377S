################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ASM_Ints.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_examples_Cpu1/external_interrupt_latency/cpu01/ASM_Ints.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="ASM_Ints.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_CodeStartBranch.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/source/F2837xS_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F2837xS_CodeStartBranch.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_DefaultISR.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/source/F2837xS_DefaultISR.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F2837xS_DefaultISR.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_GlobalVariableDefs.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/source/F2837xS_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F2837xS_GlobalVariableDefs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_Gpio.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/source/F2837xS_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F2837xS_Gpio.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_PieCtrl.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/source/F2837xS_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F2837xS_PieCtrl.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_PieVect.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/source/F2837xS_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F2837xS_PieVect.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_SysCtrl.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/source/F2837xS_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F2837xS_SysCtrl.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_usDelay.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/source/F2837xS_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F2837xS_usDelay.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

external_interrupt_latency.obj: C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_examples_Cpu1/external_interrupt_latency/cpu01/external_interrupt_latency.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --opt_for_speed=2 --include_path="C:/ti/c2000_15.12.3.LTS/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_headers/include" --include_path="C:/ti/controlSUITE/device_support/F2837xS/v210/F2837xS_common/include" -g --define=CPU1 --define=_FLASH --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="external_interrupt_latency.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


