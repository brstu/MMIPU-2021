################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/plcnext_lab3.cpp 

OBJS += \
./src/plcnext_lab3.o 

CPP_DEPS += \
./src/plcnext_lab3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-pxc-linux-gnueabi-g++ -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a9 --sysroot=/opt/pxc/sdk/AXCF2152/2020.0/sysroots/cortexa9t2hf-neon-pxc-linux-gnueabi -fno-gnu-unique -DARP_DEVICE_AXCF2152 -I/opt/pxc/sdk/AXCF2152/2020.0/sysroots/cortexa9t2hf-neon-pxc-linux-gnueabi/usr/include/plcnext -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


