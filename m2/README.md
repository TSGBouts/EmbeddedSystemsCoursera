# C1M2 Assignment – Coursera Introduction to Embedded Systems

This repository contains my solution for the **C1M2** peer-graded assignment in Coursera’s “Introduction to Embedded Systems” (University of Colorado).
I have **not** modified any of the provided C source or header files; all work is confined to:

- **Makefile** (`m2/src/Makefile`)
- **sources.mk** (`m2/src/sources.mk`)

---

- **Pattern rules**
  - `%.i` → preprocessed C (`-E`)
  - `%.asm` → assembly output (`-S`)
  - `%.o` → object file (`-c`)
- **Phony targets**
  - `compile-all`: compile all `.c` → `.o` (no linking)
  - `build`: link objects into `c1m2.out`
  - `clean`: remove **all** generated files (`*.i`, `*.asm`, `*.o`, `c1m2.out`, `c1m2.size`)
  - `size-report`: run `size c1m2.out` → `c1m2.size`
- **Platform support** (via `PLATFORM` variable)
  - `HOST`: native PC build with `gcc`
  - `MSP432`: cross-compile with `arm-none-eabi-gcc`

### sources.mk (`m2/src/sources.mk`)

- Defines
  - `COMMON_SRCS` (shared C files)
  - `MSP432_SRCS` (startup, system, interrupts)
- Conditionally sets
  ```make
  ifeq ($(PLATFORM),MSP432)
    SOURCES := $(COMMON_SRCS) $(MSP432_SRCS)
  else
    SOURCES := $(COMMON_SRCS)
  endif

## Directory Structure

m2/
├── include/ # Provided headers
├── msp432p401r.lds # MSP432 linker script
└── src/
├── Makefile # Build rules
├── sources.mk # Source lists & include paths
├── main.c # Provided
├── memory.c # Provided
├── startup_msp432p401r_gcc.c
├── system_msp432p401r.c
├── interrupts_msp432p401r_gcc.c
└── (generated: *.o, *.i, *.asm, c1m2.out, c1m2.size)

## How to Use

1. **MSP432 Cross-Compile**
   ```bash
   cd m2/src
   make clean
   make build PLATFORM=HOST
   ./c1m2.out
   size c1m2.out

2. **Host Build (on your PC)**
```cd m2/src
make clean
make build PLATFORM=MSP432
# c1m2.out is now an ARM ELF executable
# To generate Intel HEX:
arm-none-eabi-objcopy -O ihex c1m2.out c1m2.hex
# To flash to MSP432:
mspdebug rf2500 "prog c1m2.hex"

3. **Clean All Outputs**
```make clean

4. **Generate Size Report**
```make size-report PLATFORM=HOST
cat c1m2.size

## Notes:
No changes were made to any .c or .h files—only the build system was authored.
The HOST build uses your system’s gcc.
The MSP432 build requires arm-none-eabi-gcc (v9+ recommended for Cortex-M4 support).

