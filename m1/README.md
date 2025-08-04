# Array Statistics in C

This project computes basic statistical metrics (mean, median, minimum, maximum) for an array of `unsigned char` elements in C. It also includes functionality to sort and print the array.

## Files

- `stats.c` – Main logic: implements sorting and statistical functions.
- `stats.h` – Function prototypes and header guard.

## Features

- `print_array()` – Display array contents.
- `find_mean()` – Calculate the average value (float, two decimals).
- `find_median()` – Calculate the median (after sorting).
- `find_maximum()` – Find the largest element.
- `find_minimum()` – Find the smallest element.
- `sort_array()` – Sorts the array in descending order (modifiable to ascending).

## Sample Output

Median is: 1
Maximum is: 5
Mean is: 2.00
Minimum is: 0
Sorted array: 5 2 1 0

## Compile & Run

```bash
gcc -o stats.out stats.c
./stats.out
```


