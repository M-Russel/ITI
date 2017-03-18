################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../Fast_PWM.c \
../TIMER0.c \
../TIMER0_prog.c \
../TIMER1.c \
../TIMER2.c \
../delay_ms.c 

OBJS += \
./DIO_Prog.o \
./Fast_PWM.o \
./TIMER0.o \
./TIMER0_prog.o \
./TIMER1.o \
./TIMER2.o \
./delay_ms.o 

C_DEPS += \
./DIO_Prog.d \
./Fast_PWM.d \
./TIMER0.d \
./TIMER0_prog.d \
./TIMER1.d \
./TIMER2.d \
./delay_ms.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


