################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Calculator/Calculator.c 

OBJS += \
./APP/Calculator/Calculator.o 

C_DEPS += \
./APP/Calculator/Calculator.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Calculator/%.o APP/Calculator/%.su: ../APP/Calculator/%.c APP/Calculator/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/STM32F103_MCAL/SPI" -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/STM32F103_MCAL/EXTI" -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/APP/Calculator" -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/HAL/Keypad" -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/STM32F103_MCAL" -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/HAL/LCD" -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/STM32F103_MCAL/GPIO" -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/STM32F103_MCAL/RCC" -I"F:/Embedded/LearnInDepth/WS/STM32F103xx_SW/STM32F103_MCAL/UART" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP-2f-Calculator

clean-APP-2f-Calculator:
	-$(RM) ./APP/Calculator/Calculator.d ./APP/Calculator/Calculator.o ./APP/Calculator/Calculator.su

.PHONY: clean-APP-2f-Calculator

