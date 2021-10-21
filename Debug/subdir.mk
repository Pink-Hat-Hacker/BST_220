################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MainJokes.cpp \
../Student.cpp \
../TreeInterface.cpp \
../bst.cpp \
../bstNode.cpp 

OBJS += \
./MainJokes.o \
./Student.o \
./TreeInterface.o \
./bst.o \
./bstNode.o 

CPP_DEPS += \
./MainJokes.d \
./Student.d \
./TreeInterface.d \
./bst.d \
./bstNode.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


