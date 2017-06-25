################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/model/productlinkedlist.c \
../src/model/producto.c \
../src/model/userlinkedlist.c \
../src/model/usuarios.c 

OBJS += \
./src/model/productlinkedlist.o \
./src/model/producto.o \
./src/model/userlinkedlist.o \
./src/model/usuarios.o 

C_DEPS += \
./src/model/productlinkedlist.d \
./src/model/producto.d \
./src/model/userlinkedlist.d \
./src/model/usuarios.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/%.o: ../src/model/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"C:\SysGCC\Raspberry\include" -I"C:\SysGCC\usr\includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


