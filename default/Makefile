###############################################################################
# Makefile for the project lab10
###############################################################################

## General Flags
PROJECT = lab10
MCU = atmega128
TARGET = lab10.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -DF_CPU=7372800UL -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=lab10.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = MAIN.o BUZZER.o RINGBUFFER.o UART.o LED.o interrupt.o Motor.o PSD.o LineSensor.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) lab10.hex lab10.eep lab10.lss size

## Compile
MAIN.o: ../MAIN.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

BUZZER.o: ../BUZZER.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

RINGBUFFER.o: ../RINGBUFFER.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

UART.o: ../UART.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

LED.o: ../LED.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

interrupt.o: ../interrupt.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Motor.o: ../Motor.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

PSD.o: ../PSD.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

LineSensor.o: ../LineSensor.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) lab10.elf dep/* lab10.hex lab10.eep lab10.lss lab10.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

