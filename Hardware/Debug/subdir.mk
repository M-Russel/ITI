################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../KEYPAD_Prog.c \
../KEYPAD_Prog2.c \
../LCD_Prog.c \
../SWITCH_Prog.c \
../Stepper.c \
../delay_ms.c \
../main.c \
../switch.c 

OBJS += \
./DIO_Prog.o \
./KEYPAD_Prog.o \
./KEYPAD_Prog2.o \
./LCD_Prog.o \
./SWITCH_Prog.o \
./Stepper.o \
./delay_ms.o \
./main.o \
./switch.o 

C_DEPS += \
./DIO_Prog.d \
./KEYPAD_Prog.d \
./KEYPAD_Prog2.d \
./LCD_Prog.d \
./SWITCH_Prog.d \
./Stepper.d \
./delay_ms.d \
./main.d \
./switch.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


