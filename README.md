# Mini Libc - README

## Overview

This project focuses on creating a **minimal implementation of the standard C library (libc)** for Linux systems, specifically targeting the `x86_64` architecture. The library will provide essential features such as string manipulation, memory management, and POSIX-compliant file I/O operations using Linux system calls.

### Objectives
- Develop an understanding of how the C standard library operates.
- Implement key string, memory, and I/O handling functions.
- Create a freestanding `libc` that relies solely on system calls, without external library dependencies.

## Project Structure

The project consists of three main directories:
- **`libc/`**: Contains the core implementation of the mini-libc. Missing functions must be implemented.
- **`samples/`**: Contains sample use cases for the mini-libc functions.
- **`tests/`**: Contains automated tests for validating the implementation and grading.

## Building Mini Libc

To compile the mini-libc, follow these steps:

1. Navigate to the `libc/` directory:
   ```bash
   cd libc/
   ```

2. Build the library:
   ```bash
   make
   ```

3. To build the sample programs:
   ```bash
   cd ../samples/
   make
   ```

## Running Tests

Testing is automated and can be done in the `tests/` directory. Use the following commands:

1. Navigate to the `tests/` directory:
   ```bash
   cd ../tests/
   ```

2. Run all tests:
   ```bash
   make check
   ```