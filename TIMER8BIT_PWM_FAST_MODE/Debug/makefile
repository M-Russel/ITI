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
TIMER8BIT_PWM_FAST_MODE.lss \

FLASH_IMAGE += \
TIMER8BIT_PWM_FAST_MODE.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TIMER8BIT_PWM_FAST_MODE.elf secondary-outputs

# Tool invocations
TIMER8BIT_PWM_FAST_MODE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TIMER8BIT_PWM_FAST_MODE.map -mmcu=atmega32 -o "TIMER8BIT_PWM_FAST_MODE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TIMER8BIT_PWM_FAST_MODE.lss: TIMER8BIT_PWM_FAST_MODE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TIMER8BIT_PWM_FAST_MODE.elf  >"TIMER8BIT_PWM_FAST_MODE.lss"
	@echo 'Finished building: $@'
	@echo ' '

TIMER8BIT_PWM_FAST_MODE.hex: TIMER8BIT_PWM_FAST_MODE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TIMER8BIT_PWM_FAST_MODE.elf  "TIMER8BIT_PWM_FAST_MODE.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TIMER8BIT_PWM_FAST_MODE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TIMER8BIT_PWM_FAST_MODE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TIMER8BIT_PWM_FAST_MODE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
