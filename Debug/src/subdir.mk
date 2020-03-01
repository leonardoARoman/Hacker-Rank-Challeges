################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/constans.c \
../src/countingpairs.c \
../src/countingvalleys.c \
../src/magicsquare.c 

OBJS += \
./src/constans.o \
./src/countingpairs.o \
./src/countingvalleys.o \
./src/magicsquare.o 

C_DEPS += \
./src/constans.d \
./src/countingpairs.d \
./src/countingvalleys.d \
./src/magicsquare.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/Users/leoroman/eclipsecpp-workspace/hackerranksolutions/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


