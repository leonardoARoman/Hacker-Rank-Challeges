################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../designpatterns/observer/interface/publisher.c 

OBJS += \
./designpatterns/observer/interface/publisher.o 

C_DEPS += \
./designpatterns/observer/interface/publisher.d 


# Each subdirectory must supply rules for building sources it contributes
designpatterns/observer/interface/%.o: ../designpatterns/observer/interface/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/Users/leoroman/eclipsecpp-workspace/hackerranksolutions/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


