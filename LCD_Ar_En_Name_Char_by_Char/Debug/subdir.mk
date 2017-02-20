################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../DIO_voidInitialize.c \
../LCD_Prog.c \
../My_Name_Moving_Arabic_English.c \
../delay_ms.c 

OBJS += \
./DIO_Prog.o \
./DIO_voidInitialize.o \
./LCD_Prog.o \
./My_Name_Moving_Arabic_English.o \
./delay_ms.o 

C_DEPS += \
./DIO_Prog.d \
./DIO_voidInitialize.d \
./LCD_Prog.d \
./My_Name_Moving_Arabic_English.d \
./delay_ms.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


