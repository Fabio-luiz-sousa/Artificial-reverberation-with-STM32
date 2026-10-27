################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Schroeder_Reverb/Delay.c \
../Schroeder_Reverb/Schroeder_Reverb.c 

OBJS += \
./Schroeder_Reverb/Delay.o \
./Schroeder_Reverb/Schroeder_Reverb.o 

C_DEPS += \
./Schroeder_Reverb/Delay.d \
./Schroeder_Reverb/Schroeder_Reverb.d 


# Each subdirectory must supply rules for building sources it contributes
Schroeder_Reverb/%.o Schroeder_Reverb/%.su Schroeder_Reverb/%.cyclo: ../Schroeder_Reverb/%.c Schroeder_Reverb/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"/run/media/fabioluiz/arqs_linux/stm_projects/projeto_tcc/Schroeder_Reverb" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"/run/media/fabioluiz/arqs_linux/stm_projects/projeto_tcc/Schroeder_Reverb" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Schroeder_Reverb

clean-Schroeder_Reverb:
	-$(RM) ./Schroeder_Reverb/Delay.cyclo ./Schroeder_Reverb/Delay.d ./Schroeder_Reverb/Delay.o ./Schroeder_Reverb/Delay.su ./Schroeder_Reverb/Schroeder_Reverb.cyclo ./Schroeder_Reverb/Schroeder_Reverb.d ./Schroeder_Reverb/Schroeder_Reverb.o ./Schroeder_Reverb/Schroeder_Reverb.su

.PHONY: clean-Schroeder_Reverb

