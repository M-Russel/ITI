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
Free_RTOS.lss \

FLASH_IMAGE += \
Free_RTOS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Free_RTOS.elf secondary-outputs

# Tool invocations
Free_RTOS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Free_RTOS.map -mmcu=atmega16 -o "Free_RTOS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Free_RTOS.lss: Free_RTOS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Free_RTOS.elf  >"Free_RTOS.lss"
	@echo 'Finished building: $@'
	@echo ' '

Free_RTOS.hex: Free_RTOS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Free_RTOS.elf  "Free_RTOS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Free_RTOS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Free_RTOS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Free_RTOS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
