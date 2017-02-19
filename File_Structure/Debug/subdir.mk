################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../DIO_voidInitialize.c \
../LCD_Prog.c \
../delay_ms.c \
../main.c \
../switch.c 

OBJS += \
./DIO_Prog.o \
./DIO_voidInitialize.o \
./LCD_Prog.o \
./delay_ms.o \
./main.o \
./switch.o 

C_DEPS += \
./DIO_Prog.d \
./DIO_voidInitialize.d \
./LCD_Prog.d \
./delay_ms.d \
./main.d \
./switch.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/lib/avr/include -I/usr/lib/gcc/avr/4.8.2/include -I/usr/lib/gcc/avr/4.8.2/include-fixed -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


