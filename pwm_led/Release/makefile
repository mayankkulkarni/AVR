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
pwm_led.lss \

FLASH_IMAGE += \
pwm_led.hex \

EEPROM_IMAGE += \
pwm_led.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: pwm_led.elf secondary-outputs

# Tool invocations
pwm_led.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,pwm_led.map -mmcu=atmega16 -o "pwm_led.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

pwm_led.lss: pwm_led.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S pwm_led.elf  >"pwm_led.lss"
	@echo 'Finished building: $@'
	@echo ' '

pwm_led.hex: pwm_led.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex pwm_led.elf  "pwm_led.hex"
	@echo 'Finished building: $@'
	@echo ' '

pwm_led.eep: pwm_led.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex pwm_led.elf  "pwm_led.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: pwm_led.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 pwm_led.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) pwm_led.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
