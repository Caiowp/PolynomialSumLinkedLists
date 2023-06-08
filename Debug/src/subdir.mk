################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/listADT.c \
../src/main.c \
../src/poly.c 

C_DEPS += \
./src/listADT.d \
./src/main.d \
./src/poly.d 

OBJS += \
./src/listADT.o \
./src/main.o \
./src/poly.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/listADT.d ./src/listADT.o ./src/main.d ./src/main.o ./src/poly.d ./src/poly.o

.PHONY: clean-src

