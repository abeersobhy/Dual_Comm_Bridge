################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103_MCAL/UART/subdir.mk
-include STM32F103_MCAL/SPI/subdir.mk
-include STM32F103_MCAL/RCC/subdir.mk
-include STM32F103_MCAL/GPIO/subdir.mk
-include STM32F103_MCAL/EXTI/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keypad/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := STM32F103xx_SW
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F103xx_SW.elf \

MAP_FILES += \
STM32F103xx_SW.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F103xx_SW.list \

OBJCOPY_HEX += \
STM32F103xx_SW.hex \

OBJCOPY_BIN += \
STM32F103xx_SW.bin \


# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: STM32F103xx_SW.elf secondary-outputs

# Tool invocations
STM32F103xx_SW.elf STM32F103xx_SW.map: $(OBJS) $(USER_OBJS) F:\Embedded\LearnInDepth\WS\STM32F103xx_SW\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "STM32F103xx_SW.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\Embedded\LearnInDepth\WS\STM32F103xx_SW\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32F103xx_SW.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F103xx_SW.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F103xx_SW.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103xx_SW.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "STM32F103xx_SW.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103xx_SW.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F103xx_SW.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) STM32F103xx_SW.bin STM32F103xx_SW.elf STM32F103xx_SW.hex STM32F103xx_SW.list STM32F103xx_SW.map default.size.stdout
	-@echo ' '

post-build:
	"E:\Apps\STM32CubeIDE_1.10.0\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.win32_2.0.300.202205161323\tools\bin\STM32_Programmer_CLI.exe" -c port=SWD mode=UR -d "STM32F103xx_SW.elf" -v -rst
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified post-build

-include ../makefile.targets
