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
File_Structure.lss \

FLASH_IMAGE += \
File_Structure.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: File_Structure.elf secondary-outputs

# Tool invocations
File_Structure.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,File_Structure.map -mmcu=atmega32 -o "File_Structure.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

File_Structure.lss: File_Structure.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S File_Structure.elf  >"File_Structure.lss"
	@echo 'Finished building: $@'
	@echo ' '

File_Structure.hex: File_Structure.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex File_Structure.elf  "File_Structure.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: File_Structure.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 File_Structure.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) File_Structure.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
