#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

OBJS := $(SOURCES:.c=.o)

# Platform Overrides
PLATFORM ?= HOST

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds 
CPU = cortex‑m4
ARC = thumb
SPECS = nosys.specs
MARCH = armv7e-m
FPU   = fpv4-sp-d16
ABI   = hard

PLATFORM_FLAGS = \
-mcpu=$(CPU) \
-m$(ARC) \
-march=$(MARCH) \
-mfpu=$(FPU) \
-mfloat-abi=$(ABI) \
--specs=$(SPECS)

# Compiler Flags and Defines
CFLAGS = \
-D$(PLATFORM) \
-g \
-Werror \
-std=c99

ifeq ($(PLATFORM),MSP432)
CC      := arm-none-eabi-gcc
LD      := $(CC)
CFLAGS += $(PLATFORM_FLAGS)
LDFLAGS += -T$(LINKER_FILE) $(PLATFORM_FLAGS)
else ifeq ($(PLATFORM),HOST)
CC      := gcc
LD      := $(CC)
# no extra flags for HOST
else
$(error Unsupported PLATFORM '$(PLATFORM)'; use MSP432 or HOST)
endif

ifeq ($(VERBOSE), 1)
	CFLAGS += -DVERBOSE
endif

CPPFLAGS := -DPLATFORM=$(PLATFORM) $(addprefix -I, $(INCLUDES))

%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -E $< -o $@

%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@ 

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: compile-all build clean size-report

compile-all: $(OBJS)

build:  compile-all
	$(LD) $(LDFLAGS) $(OBJS) -o c1m2.out

clean:
	rm -f *.i *.o *.asm c1m2.out c1m2.size

size-report: build
	size c1m2.out > c1m2.size
	@echo "Wrote size report to c1m2.size"
