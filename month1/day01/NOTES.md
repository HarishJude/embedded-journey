# Day 1 Notes: C vs Java

## 1. Integer overflow wraps silently
- `unsigned long` is 64 bits on my WSL Linux, so the max is 2^64 - 1.
- 25! needs about 84 bits. Only the low 64 bits are kept, so I got
  7034535277573963776 (= 25! mod 2^64). No error, no warning.
- Unsigned overflow wraps (defined behavior). Signed overflow is
  undefined behavior.
- On STM32, `unsigned long` is 32 bits, so 13! already overflows.
  Embedded code uses `uint32_t` / `uint64_t` for exact sizes.

## 2. `#include` pastes, Java `import` only names
- `#include` copies the header's text into my file before compiling.
- See it with `gcc -E hello.c | less`.
- Java's `import` only tells the compiler where a class lives.

## 3. No virtual machine
- `gcc` compiles straight to native machine code. No JVM, no bytecode.
- Run with `./program`.

## 4. Integer division truncates
- `5 / 9` is `0` in C because both operands are ints.
- Use `9.0 / 5.0` for floating-point division (temp_convert.c).

## 5. Type sizes are not fixed by the language
- `sizeof` returns the fixed size of a type in bytes. It never depends
  on the value stored.
- The C standard only guarantees minimum sizes. The compiler and
  platform pick the real size.
- Use `%zu` to print a `sizeof` result.

## 6. Pointer size = address width of the machine
- A pointer stores an address, so its size matches the system:
  64-bit = 8 bytes, 32-bit = 4 bytes, 8-bit AVR = 2 bytes.
- All pointer types (`char *`, `int *`, `double *`) are the same size.
  The type only says how to read the memory at that address.

## 7. Every variable stores all its bits
- A 64-bit `1` is 63 zeros then a 1. Leading zeros are real bits.
- `-1` in a 32-bit `int` has every bit set (two's complement), so it
  prints as `ffffffff` in hex.

## sizes.c results (64-bit Linux, WSL)
| Type | Bytes |
|---|---|
| char | 1 |
| short | 2 |
| int | 4 |
| long | 8 |
| long long | 8 |
| float | 4 |
| double | 8 |
| int * | 8 |

On my machine `long` is 8 bytes, but on STM32 it would be 4 bytes.
On STM32, `int *` is 4 bytes.

## Commands learned
- Compile and run: `gcc -Wall -Wextra -g file.c -o file && ./file`
- View preprocessed output: `gcc -E file.c | less`
- `&&` runs the next command only if the previous one succeeded.