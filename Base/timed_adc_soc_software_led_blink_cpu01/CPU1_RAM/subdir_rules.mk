################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
F2837xS_Adc.obj: ../F2837xS_Adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_Adc.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_CodeStartBranch.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/source/F2837xS_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_CodeStartBranch.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_CpuTimers.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/source/F2837xS_CpuTimers.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_CpuTimers.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_DefaultISR.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/source/F2837xS_DefaultISR.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_DefaultISR.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_GlobalVariableDefs.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/source/F2837xS_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_GlobalVariableDefs.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_Gpio.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/source/F2837xS_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_Gpio.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_PieCtrl.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/source/F2837xS_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_PieCtrl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_PieVect.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/source/F2837xS_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_PieVect.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_SysCtrl.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/source/F2837xS_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_SysCtrl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_usDelay.obj: C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/source/F2837xS_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_usDelay.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

timed_adc_soc_software_led_blink_cpu01.obj: ../timed_adc_soc_software_led_blink_cpu01.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/include" --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="timed_adc_soc_software_led_blink_cpu01.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


