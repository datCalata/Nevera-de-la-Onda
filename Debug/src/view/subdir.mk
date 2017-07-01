################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/view/display.c \
../src/view/lcd.c 

OBJS += \
./src/view/display.o \
./src/view/lcd.o 

C_DEPS += \
./src/view/display.d \
./src/view/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
src/view/%.o: ../src/view/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"C:\SysGCC\Raspberry\include" -I"C:\SysGCC\usr\includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


