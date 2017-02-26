################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../EXTINT_prog.c \
../ICU.c \
../LCD_Prog.c \
../TIMER0_prog.c \
../delay_ms.c 

OBJS += \
./DIO_Prog.o \
./EXTINT_prog.o \
./ICU.o \
./LCD_Prog.o \
./TIMER0_prog.o \
./delay_ms.o 

C_DEPS += \
./DIO_Prog.d \
./EXTINT_prog.d \
./ICU.d \
./LCD_Prog.d \
./TIMER0_prog.d \
./delay_ms.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


