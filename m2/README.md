# C1M2 Assignment – Introduction to Embedded Systems (Coursera)

## Overview

This repository contains my solution for the **C1M2 peer‑graded assignment** from Coursera’s *Introduction to Embedded Systems* (University of Colorado).

All modifications are confined to the build system files:

- `Makefile` (`m2/src/Makefile`)
- `sources.mk` (`m2/src/sources.mk`)

No source `.c` or `.h` files have been altered.

## Features

### Pattern Rules

- `%.i` → preprocessed C (`-E`)  
- `%.asm` → assembly output (`-S`)  
- `%.o` → object file (`-c`)

### Phony Targets

- `compile-all`: compile all `.c` → `.o` (no linking)  
- `build`: link object files into `c1m2.out`  
- `clean`: remove all generated files (`*.i`, `*.asm`, `*.o`, `c1m2.out`, `c1m2.size`)  
- `size-report`: run `size c1m2.out` and output to `c1m2.size`

### Platform Support

Specified by the `PLATFORM` variable:

- `HOST`: native PC build using `gcc`  
- `MSP432`: cross‑compile with `arm‑none‑eabi‑gcc`

## Project Structure

```bash
m2/
├── include/ # Provided headers
├── msp432p401r.lds # MSP432 linker script
└── src/
├── Makefile # Build definitions
├── sources.mk # Source file lists
├── main.c # Provided
├── memory.c # Provided
├── startup_msp432p401r_gcc.c
├── system_msp432p401r.c
├── interrupts_msp432p401r_gcc.c
└── generated: *.i, *.asm, *.o, c1m2.out, c1m2.size
```

## Usage

### Build for HOST

```bash
cd m2/src
make clean
make build PLATFORM=HOST
./c1m2.out
size c1m2.out
```

### Build for MSP432 (ARM Cortex‑M4)

```bash
cd m2/src
make clean
make build PLATFORM=MSP432
```

### Generate Intel HEX file
```bash
arm-none-eabi-objcopy -O ihex c1m2.out c1m2.hex
```

### Flash to device (using mspdebug)
```bash
mspdebug rf2500 "prog c1m2.hex"
```

### Cleaning
```bash
cd m2/src
make clean
```

### Generate Size Report
```bash
make size-report PLATFORM=HOST
cat c1m2.size
```

## Requirements
HOST build: needs system gcc.
MSP432 build: arm-none-eabi-gcc (v9+ recommended for Cortex‑M4 support).

