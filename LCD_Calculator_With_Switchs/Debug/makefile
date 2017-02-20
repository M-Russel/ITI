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
LCD_Calculator_With_Switchs.lss \

FLASH_IMAGE += \
LCD_Calculator_With_Switchs.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LCD_Calculator_With_Switchs.elf secondary-outputs

# Tool invocations
LCD_Calculator_With_Switchs.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LCD_Calculator_With_Switchs.map -mmcu=atmega32 -o "LCD_Calculator_With_Switchs.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD_Calculator_With_Switchs.lss: LCD_Calculator_With_Switchs.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD_Calculator_With_Switchs.elf  >"LCD_Calculator_With_Switchs.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCD_Calculator_With_Switchs.hex: LCD_Calculator_With_Switchs.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCD_Calculator_With_Switchs.elf  "LCD_Calculator_With_Switchs.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD_Calculator_With_Switchs.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LCD_Calculator_With_Switchs.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD_Calculator_With_Switchs.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
