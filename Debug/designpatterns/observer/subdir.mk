################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../designpatterns/observer/observer_phonealert.c \
../designpatterns/observer/observer_phonescreen.c 

OBJS += \
./designpatterns/observer/observer_phonealert.o \
./designpatterns/observer/observer_phonescreen.o 

C_DEPS += \
./designpatterns/observer/observer_phonealert.d \
./designpatterns/observer/observer_phonescreen.d 


# Each subdirectory must supply rules for building sources it contributes
designpatterns/observer/%.o: ../designpatterns/observer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/Users/leoroman/eclipsecpp-workspace/hackerranksolutions/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


