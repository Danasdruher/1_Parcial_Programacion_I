################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/1_Parcial_Programacion_I.c \
../src/marca.c \
../src/notebook.c \
../src/tipo.c 

C_DEPS += \
./src/1_Parcial_Programacion_I.d \
./src/marca.d \
./src/notebook.d \
./src/tipo.d 

OBJS += \
./src/1_Parcial_Programacion_I.o \
./src/marca.o \
./src/notebook.o \
./src/tipo.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/1_Parcial_Programacion_I.d ./src/1_Parcial_Programacion_I.o ./src/marca.d ./src/marca.o ./src/notebook.d ./src/notebook.o ./src/tipo.d ./src/tipo.o

.PHONY: clean-src

