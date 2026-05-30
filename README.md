*This project has been created as part of the 42 curriculum by wmezgoli.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf`. The goal of this project is to understand variadic functions, format string parsing, and low-level output by building a functional subset of `printf` from scratch.

The function handles the following format specifiers:

- `%c` — single character
- `%s` — string
- `%p` — pointer address (hexadecimal)
- `%d` / `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` / `%X` — unsigned hexadecimal integer (lower/uppercase)
- `%%` — literal percent sign

The function returns the total number of characters printed, mirroring the behavior of the original `printf`.

## Algorithm and Data Structure

The function iterates over the format string character by character using pointer arithmetic. When a `%` is encountered, the next character is passed to a dispatcher function (`ft_whatisit`) which uses `va_arg` to extract the correct argument from the variadic list and calls the appropriate output function.

A `va_list` pointer (`&arg`) is passed to the dispatcher rather than the `va_list` directly, so that `va_arg` advances the original argument list — not a local copy. Without this, each call to the dispatcher would consume from a stale copy and arguments would repeat.

Hexadecimal conversion is handled recursively: the number is divided by 16 until it is less than 16, then each digit is written on the way back up the call stack using an index into the string `"0123456789abcdef"`. Pointer addresses are cast to `unsigned long` before being passed to the hex converter to preserve all 64-bit address bits.

The return value (character count) is accumulated across all output calls and returned at the end. Error handling propagates `-1` upward and calls `va_end` before returning to avoid resource leaks.

## Instructions

### Compilation

Clone the repository and run:

```bash
make
```

This produces `libftprintf.a` at the root of the repository.

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
}
```

Compile with:

```bash
gcc main.c libftprintf.a
```

### Cleanup

```bash
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # full rebuild
```

## Resources

- [C Standard Library — printf](https://en.cppreference.com/w/c/io/fprintf) — official documentation for printf format specifiers and behavior
- [Variadic Functions in C — cppreference](https://en.cppreference.com/w/c/variadic) — reference for `va_list`, `va_start`, `va_arg`, `va_end`
- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html) — detailed explanation of formatted output internals
- [ar(1) man page](https://linux.die.net/man/1/ar) — documentation for the `ar` archiver used to create static libraries

### AI Usage

Claude (claude.ai) was used during this project for the following:

- Debugging: identifying why pointer addresses were truncated to 32 bits (caused by a precompiled header `.gch` caching an outdated `unsigned int` declaration)
- Understanding `va_list` by reference vs. by value and why `&arg` must be passed to sub-functions
- Writing this README
