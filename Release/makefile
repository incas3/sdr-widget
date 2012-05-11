################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include src/SOFTWARE_FRAMEWORK/UTILS/STARTUP_FILES/GCC/subdir.mk
-include src/SOFTWARE_FRAMEWORK/UTILS/DEBUG/subdir.mk
-include src/SOFTWARE_FRAMEWORK/SERVICES/USB/CLASS/HID/subdir.mk
-include src/SOFTWARE_FRAMEWORK/SERVICES/USB/CLASS/AUDIO/subdir.mk
-include src/SOFTWARE_FRAMEWORK/SERVICES/FREERTOS/Source/subdir.mk
-include src/SOFTWARE_FRAMEWORK/SERVICES/FREERTOS/Source/portable/MemMang/subdir.mk
-include src/SOFTWARE_FRAMEWORK/SERVICES/FREERTOS/Source/portable/GCC/AVR32_UC3/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/WDT/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/USBB/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/USBB/ENUM/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/USBB/ENUM/DEVICE/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/USART/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/TWIM/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/TC/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/SSC/I2S/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/RTC/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/PM/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/PDCA/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/INTC/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/GPIO/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/FLASHC/subdir.mk
-include src/SOFTWARE_FRAMEWORK/DRIVERS/EIC/subdir.mk
-include src/SOFTWARE_FRAMEWORK/BOARDS/SDRwdgtLite/subdir.mk
-include src/SOFTWARE_FRAMEWORK/ASM/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OBJCOPY = avr32-objcopy
# Output format. (can be srec, ihex, binary)
FORMAT = ihex
SIZE = avr32-size
TARGET = widget

HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex
ELFSIZE = $(SIZE) $(MCU_FLAG) $(FORMAT_FLAG) $(TARGET).elf

TARGET_MCU = at32uc3a3256
PROGRAMMER = ../../dfu-programmer-0.5.4/src/dfu-programmer

# Define Messages
# English
MSG_ERRORS_NONE = Errors: none
MSG_BEGIN = -------- begin --------
MSG_END = --------  end  --------
MSG_SIZE_BEFORE = Size before: 
MSG_SIZE_AFTER = Size after:
MSG_COFF = Converting to AVR COFF:
MSG_EXTENDED_COFF = Converting to AVR Extended COFF:
MSG_FLASH = Creating load file for Flash:
MSG_EEPROM = Creating load file for EEPROM:
MSG_EXTENDED_LISTING = Creating Extended Listing:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = Linking:
MSG_COMPILING = Compiling C:
MSG_COMPILING_CPP = Compiling C++:
MSG_ASSEMBLING = Assembling:
MSG_CLEANING = Cleaning project:
MSG_CREATING_LIBRARY = Creating library:

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: build

build: elf hex sizebefore sizeafter

elf: $(TARGET).elf
hex: $(TARGET).hex
eep: $(TARGET).eep
lss: $(TARGET).lss
sym: $(TARGET).sym

sizebefore:
	@if test -f $(TARGET).elf; then echo; echo $(MSG_SIZE_AFTER); $(ELFSIZE); \
	2>/dev/null; echo; fi

sizeafter:
	@if test -f $(TARGET).elf; then echo; echo $(MSG_SIZE_AFTER); $(HEXSIZE); \
	2>/dev/null; echo; fi

# Create final output files (.hex, .eep) from ELF output file.
%.hex: %.elf
	@echo
	@echo $(MSG_FLASH) $@
	$(OBJCOPY) -O $(FORMAT) $< $@

# Tool invocations
widget.elf: $(OBJS) $(USER_OBJS)
	@echo Link $@
	@avr32-gcc -nostartfiles -Wl,--gc-sections -Wl,-e,_trampoline -mpart=uc3a3256 -Wl,--gc-sections --rodata-writable -Wl,--direct-data -o"$(TARGET).elf" $(OBJS) $(USER_OBJS) $(LIBS)

# Other Targets

program: hex
	$(PROGRAMMER) $(TARGET_MCU) erase
	$(PROGRAMMER) $(TARGET_MCU) flash  --suppress-bootloader-mem $(TARGET).hex --debug 6
	$(PROGRAMMER) $(TARGET_MCU) reset

clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) widget.elf widget.hex

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

