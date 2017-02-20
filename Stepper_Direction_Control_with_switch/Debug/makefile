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
Stepper_Direction_Control_with_switch.lss \

FLASH_IMAGE += \
Stepper_Direction_Control_with_switch.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Stepper_Direction_Control_with_switch.elf secondary-outputs

# Tool invocations
Stepper_Direction_Control_with_switch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Stepper_Direction_Control_with_switch.map -mmcu=atmega32 -o "Stepper_Direction_Control_with_switch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Stepper_Direction_Control_with_switch.lss: Stepper_Direction_Control_with_switch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Stepper_Direction_Control_with_switch.elf  >"Stepper_Direction_Control_with_switch.lss"
	@echo 'Finished building: $@'
	@echo ' '

Stepper_Direction_Control_with_switch.hex: Stepper_Direction_Control_with_switch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Stepper_Direction_Control_with_switch.elf  "Stepper_Direction_Control_with_switch.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Stepper_Direction_Control_with_switch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Stepper_Direction_Control_with_switch.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Stepper_Direction_Control_with_switch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
