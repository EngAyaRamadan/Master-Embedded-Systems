################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32_f103c6_Drivers/LCD_DRIVER/subdir.mk
-include stm32_f103c6_Drivers/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
unit8_lesson3.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
unit8_lesson3.list \

OBJCOPY_HEX += \
unit8_lesson3.hex \

OBJCOPY_BIN += \
unit8_lesson3.bin \


# All Target
all: unit8_lesson3.elf secondary-outputs

# Tool invocations
unit8_lesson3.elf: $(OBJS) $(USER_OBJS) C:\Users\QUADRO\STM32CubeIDE\workspace_1.4.0\unit8_lesson3\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "unit8_lesson3.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\QUADRO\STM32CubeIDE\workspace_1.4.0\unit8_lesson3\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="unit8_lesson3.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

unit8_lesson3.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "unit8_lesson3.list"
	@echo 'Finished building: $@'
	@echo ' '

unit8_lesson3.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "unit8_lesson3.hex"
	@echo 'Finished building: $@'
	@echo ' '

unit8_lesson3.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "unit8_lesson3.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
