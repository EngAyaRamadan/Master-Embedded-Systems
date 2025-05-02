################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_Drivers/LCD_DRIVER/lcd.c 

OBJS += \
./stm32f103c6_Drivers/LCD_DRIVER/lcd.o 

C_DEPS += \
./stm32f103c6_Drivers/LCD_DRIVER/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_Drivers/LCD_DRIVER/lcd.o: ../stm32f103c6_Drivers/LCD_DRIVER/lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit7_lesson_3_section/stm32f103c6_Drivers/inc" -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit7_lesson_3_section/stm32f103c6_Drivers/KEYPAD_DRIVER" -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit7_lesson_3_section/stm32f103c6_Drivers/LCD_DRIVER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/LCD_DRIVER/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

