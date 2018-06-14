################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
2837x_examples_setup.obj: C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/examples/common/2837x_examples_setup.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="2837x_examples_setup.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

2837x_sincos.obj: C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/2837x_sincos.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="2837x_sincos.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_CodeStartBranch.obj: C:/Users/adria/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_CodeStartBranch.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_DefaultISR.obj: C:/Users/adria/device_support/f2837xd/common/source/F2837xD_DefaultISR.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_DefaultISR.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_GlobalVariableDefs.obj: C:/Users/adria/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_GlobalVariableDefs.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_Gpio.obj: C:/Users/adria/device_support/f2837xd/common/source/F2837xD_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_Gpio.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_Ipc.obj: C:/Users/adria/device_support/f2837xd/common/source/F2837xD_Ipc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_Ipc.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_PieCtrl.obj: C:/Users/adria/device_support/f2837xd/common/source/F2837xD_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_PieCtrl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_PieVect.obj: C:/Users/adria/device_support/f2837xd/common/source/F2837xD_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_PieVect.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_SysCtrl.obj: C:/Users/adria/device_support/f2837xd/common/source/F2837xD_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_SysCtrl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_usDelay.obj: C:/Users/adria/device_support/f2837xd/common/source/F2837xD_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_usDelay.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

sincos.obj: C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/sincos.cla $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --include_path="C:/ti/ti-cgt-c2000_18.1.1.LTS/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/CLA/2837x_sincos/cpu01/" --include_path="C:/Users/adria/device_support/f2837xd/common/include" --include_path="C:/Users/adria/device_support/f2837xd/headers/include" --include_path="C:/Users/adria/Dropbox/GitHub/LAUNCHXL-F28377S/Base/include" -g --define=RAM --define=CLA_MATH_TABLES_IN_ROM --define=CPU1 --diag_warning=225 --preproc_with_compile --preproc_dependency="sincos.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


