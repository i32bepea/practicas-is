################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Agenda.cpp \
../Contacto.cpp \
../GestorCS.cpp \
../Menu.cpp 

OBJS += \
./Agenda.o \
./Contacto.o \
./GestorCS.o \
./Menu.o 

CPP_DEPS += \
./Agenda.d \
./Contacto.d \
./GestorCS.d \
./Menu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


