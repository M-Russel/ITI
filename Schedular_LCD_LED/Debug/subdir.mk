################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../LCD_Prog.c \
../STEPPER_prog.c \
../TIMER0_prog.c \
../TIMER1.c \
../TIMER2.c \
../delay_ms.c \
../schedular0.c 

OBJS += \
./DIO_Prog.o \
./LCD_Prog.o \
./STEPPER_prog.o \
./TIMER0_prog.o \
./TIMER1.o \
./TIMER2.o \
./delay_ms.o \
./schedular0.o 

C_DEPS += \
./DIO_Prog.d \
./LCD_Prog.d \
./STEPPER_prog.d \
./TIMER0_prog.d \
./TIMER1.d \
./TIMER2.d \
./delay_ms.d \
./schedular0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


