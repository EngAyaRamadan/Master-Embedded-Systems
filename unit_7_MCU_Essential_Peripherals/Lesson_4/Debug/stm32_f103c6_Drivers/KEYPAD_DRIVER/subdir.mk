################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_Drivers/KEYPAD_DRIVER/keypad.c 

OBJS += \
./stm32_f103c6_Drivers/KEYPAD_DRIVER/keypad.o 

C_DEPS += \
./stm32_f103c6_Drivers/KEYPAD_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_Drivers/KEYPAD_DRIVER/keypad.o: ../stm32_f103c6_Drivers/KEYPAD_DRIVER/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit7_Lesson4/stm32_f103c6_Drivers/inc" -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit7_Lesson4/stm32_f103c6_Drivers/KEYPAD_DRIVER" -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit7_Lesson4/stm32_f103c6_Drivers/LCD_DRIVER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_Drivers/KEYPAD_DRIVER/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

