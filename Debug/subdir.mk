################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../constans.c \
../countingpairs.c \
../countingvalleys.c \
../driver.c \
../magicsquare.c 

OBJS += \
./constans.o \
./countingpairs.o \
./countingvalleys.o \
./driver.o \
./magicsquare.o 

C_DEPS += \
./constans.d \
./countingpairs.d \
./countingvalleys.d \
./driver.d \
./magicsquare.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


