################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Agenda(falla).cpp \
../Agenda.cpp \
../Contacto.cpp 

OBJS += \
./Agenda(falla).o \
./Agenda.o \
./Contacto.o 

CPP_DEPS += \
./Agenda(falla).d \
./Agenda.d \
./Contacto.d 


# Each subdirectory must supply rules for building sources it contributes
Agenda(falla).o: ../Agenda(falla).cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Agenda(falla).d" -MT"Agenda(falla).d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


