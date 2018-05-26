################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ti-cgt-c2000_18.1.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./F2837xS_Adc.obj" \
"./F2837xS_CodeStartBranch.obj" \
"./F2837xS_CpuTimers.obj" \
"./F2837xS_DefaultISR.obj" \
"./F2837xS_GlobalVariableDefs.obj" \
"./F2837xS_Gpio.obj" \
"./F2837xS_PieCtrl.obj" \
"./F2837xS_PieVect.obj" \
"./F2837xS_SysCtrl.obj" \
"./F2837xS_usDelay.obj" \
"./timed_adc_soc_software_led_blink_epwm_cpu01.obj" \
$(GEN_CMDS__FLAG) \
-lrts2800_fpu32.lib \
-l2837xS_Generic_RAM_lnk.cmd \
-lF2837xS_Headers_nonBIOS.cmd \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
timed_adc_soc_software_led_blink_epwm_cpu01.out \

EXE_OUTPUTS__QUOTED += \
"timed_adc_soc_software_led_blink_epwm_cpu01.out" \

BIN_OUTPUTS += \
timed_adc_soc_software_led_blink_epwm_cpu01.hex \

BIN_OUTPUTS__QUOTED += \
"timed_adc_soc_software_led_blink_epwm_cpu01.hex" \


# All Target
all: timed_adc_soc_software_led_blink_epwm_cpu01.out

# Tool invocations
timed_adc_soc_software_led_blink_epwm_cpu01.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --display_error_number -z -m"timed_adc_soc_software_led_blink_epwm_cpu01.map" --stack_size=0x100 --warn_sections -i"C:/ti/ti-cgt-c2000_18.1.1.LTS/lib" -i"C:/ti/ti-cgt-c2000_18.1.1.LTS/include" -i"C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/common/cmd" -i"C:/ti/c2000/C2000Ware_1_00_04_00/device_support/f2837xs/headers/cmd" --reread_libs --display_error_number --xml_link_info="timed_adc_soc_software_led_blink_epwm_cpu01_linkInfo.xml" --entry_point=code_start --rom_model -o "timed_adc_soc_software_led_blink_epwm_cpu01.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

timed_adc_soc_software_led_blink_epwm_cpu01.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ti-cgt-c2000_18.1.1.LTS/bin/hex2000"  -o "timed_adc_soc_software_led_blink_epwm_cpu01.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "F2837xS_Adc.obj" "F2837xS_CodeStartBranch.obj" "F2837xS_CpuTimers.obj" "F2837xS_DefaultISR.obj" "F2837xS_GlobalVariableDefs.obj" "F2837xS_Gpio.obj" "F2837xS_PieCtrl.obj" "F2837xS_PieVect.obj" "F2837xS_SysCtrl.obj" "F2837xS_usDelay.obj" "timed_adc_soc_software_led_blink_epwm_cpu01.obj" 
	-$(RM) "F2837xS_Adc.d" "F2837xS_CpuTimers.d" "F2837xS_DefaultISR.d" "F2837xS_GlobalVariableDefs.d" "F2837xS_Gpio.d" "F2837xS_PieCtrl.d" "F2837xS_PieVect.d" "F2837xS_SysCtrl.d" "timed_adc_soc_software_led_blink_epwm_cpu01.d" 
	-$(RM) "F2837xS_CodeStartBranch.d" "F2837xS_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

