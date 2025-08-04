# Embedded Utilities Library

A small collection of low-level C utilities for memory manipulation, dynamic allocation, and integer–ASCII conversion, designed for both MSP432 and host targets.

## Features

- **Build system**
  - Dual‐platform support via `PLATFORM` make flag (`HOST` or `MSP432`)
  - Optional debug printing controlled by `VERBOSE=1` (adds `-DVERBOSE`)
  - All `printf` calls go through a `PRINTF` macro in `platform.h`

- **Memory functions** (`memory.c` / `memory.h`)
  - `my_memmove(src, dst, len)` — overlap-safe move
  - `my_memcopy(src, dst, len)` — simple copy (undefined on overlap)
  - `my_memset(src, len, value)` — fill with a byte value
  - `my_memzero(src, len)` — fill with zeros
  - `my_reverse(src, len)` — in-place byte reversal
  - `reserve_words(n)` / `free_words(ptr)` — dynamic word allocation

- **String conversion** (`memory.c` / `memory.h`)
  - `my_itoa(data, buf, base)` — signed integer → ASCII, bases 2–16
  - `my_atoi(buf, digits, base)` — ASCII → signed integer, bases 2–16

- **Statistics module** (`stats.c` / `stats.h`)
  - `print_array(arr, len)` — debug dump, enabled only with `-DVERBOSE`
