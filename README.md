# 42 C++ Module 06

This module explores the different specific casting operators in C++ compared to C-style casting.

## Concepts
- `static_cast`
- `reinterpret_cast`
- `dynamic_cast`
- Serialization and type identification.

## Exercises
- **ex00 (Scalar conversion):** A generic converter that takes a string literal and converts it to char, int, float, and double (handling limits and special values like NaN/Inf).
- **ex01 (Serialization):** Converting pointers to `uintptr_t` and back using `reinterpret_cast`.
- **ex02 (Identify real type):** Using `dynamic_cast` to identify a class type (A, B, or C) at runtime from a base pointer.

## Usage
```bash
cd ex00
make
./convert 42.0f
