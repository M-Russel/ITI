################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
LCD_Arabic_Name_Sinsuidal_move.lss \

FLASH_IMAGE += \
LCD_Arabic_Name_Sinsuidal_move.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LCD_Arabic_Name_Sinsuidal_move.elf secondary-outputs

# Tool invocations
LCD_Arabic_Name_Sinsuidal_move.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LCD_Arabic_Name_Sinsuidal_move.map -mmcu=atmega32 -o "LCD_Arabic_Name_Sinsuidal_move.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD_Arabic_Name_Sinsuidal_move.lss: LCD_Arabic_Name_Sinsuidal_move.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD_Arabic_Name_Sinsuidal_move.elf  >"LCD_Arabic_Name_Sinsuidal_move.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCD_Arabic_Name_Sinsuidal_move.hex: LCD_Arabic_Name_Sinsuidal_move.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCD_Arabic_Name_Sinsuidal_move.elf  "LCD_Arabic_Name_Sinsuidal_move.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD_Arabic_Name_Sinsuidal_move.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LCD_Arabic_Name_Sinsuidal_move.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD_Arabic_Name_Sinsuidal_move.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
