################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_Drivers/stm32_f103c6_EXTI_driver.c \
../stm32_f103c6_Drivers/stm32_f103c6_RCC_driver.c \
../stm32_f103c6_Drivers/stm32_f103c6_SPI_driver.c \
../stm32_f103c6_Drivers/stm32_f103c6_USART_driver.c \
../stm32_f103c6_Drivers/stm32_f103c6_gpio_driver.c 

OBJS += \
./stm32_f103c6_Drivers/stm32_f103c6_EXTI_driver.o \
./stm32_f103c6_Drivers/stm32_f103c6_RCC_driver.o \
./stm32_f103c6_Drivers/stm32_f103c6_SPI_driver.o \
./stm32_f103c6_Drivers/stm32_f103c6_USART_driver.o \
./stm32_f103c6_Drivers/stm32_f103c6_gpio_driver.o 

C_DEPS += \
./stm32_f103c6_Drivers/stm32_f103c6_EXTI_driver.d \
./stm32_f103c6_Drivers/stm32_f103c6_RCC_driver.d \
./stm32_f103c6_Drivers/stm32_f103c6_SPI_driver.d \
./stm32_f103c6_Drivers/stm32_f103c6_USART_driver.d \
./stm32_f103c6_Drivers/stm32_f103c6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_Drivers/stm32_f103c6_EXTI_driver.o: ../stm32_f103c6_Drivers/stm32_f103c6_EXTI_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit8_lesson5_lab2/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_Drivers/stm32_f103c6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_f103c6_Drivers/stm32_f103c6_RCC_driver.o: ../stm32_f103c6_Drivers/stm32_f103c6_RCC_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit8_lesson5_lab2/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_Drivers/stm32_f103c6_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_f103c6_Drivers/stm32_f103c6_SPI_driver.o: ../stm32_f103c6_Drivers/stm32_f103c6_SPI_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit8_lesson5_lab2/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_Drivers/stm32_f103c6_SPI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_f103c6_Drivers/stm32_f103c6_USART_driver.o: ../stm32_f103c6_Drivers/stm32_f103c6_USART_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit8_lesson5_lab2/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_Drivers/stm32_f103c6_USART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_f103c6_Drivers/stm32_f103c6_gpio_driver.o: ../stm32_f103c6_Drivers/stm32_f103c6_gpio_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/QUADRO/STM32CubeIDE/workspace_1.4.0/unit8_lesson5_lab2/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_Drivers/stm32_f103c6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

