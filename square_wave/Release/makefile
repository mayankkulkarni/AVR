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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
square_wave.lss \

FLASH_IMAGE += \
square_wave.hex \

EEPROM_IMAGE += \
square_wave.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: square_wave.elf secondary-outputs

# Tool invocations
square_wave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,square_wave.map -mmcu=atmega16 -o "square_wave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

square_wave.lss: square_wave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S square_wave.elf  >"square_wave.lss"
	@echo 'Finished building: $@'
	@echo ' '

square_wave.hex: square_wave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex square_wave.elf  "square_wave.hex"
	@echo 'Finished building: $@'
	@echo ' '

square_wave.eep: square_wave.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex square_wave.elf  "square_wave.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: square_wave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 square_wave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) square_wave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
