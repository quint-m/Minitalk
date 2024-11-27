# libft - C Standard Library Implementation

## Description
`libft` is a custom implementation of the C Standard Library. This project includes various functions for memory management, string manipulation, mathematical operations, input/output handling, and more. It is designed for learning and understanding how C’s standard library works at a low level.

The goal of `libft` is to provide a set of useful functions for general-purpose programming, implementing many of the features provided by the standard library in C.

## Features
- Custom implementations of standard C library functions.
- Focus on memory management, string handling, and utility functions.
- Modular design with reusable components.
- Code that emphasizes learning and low-level understanding of C.

## List of Implemented Functions
- Memory Management: `malloc`, `free`, `realloc`
- String Manipulation: `strlen`, `strcpy`, `strdup`, `strcat`, `strcmp`, etc.
- Utility Functions: `isalpha`, `isdigit`, `toupper`, `tolower`, etc.
- Math Functions: `abs`, `pow`, etc.
- Input/Output: `putchar`, `puts`, `getchar`, etc.

## Installation

To use `libft`, you can clone this repository and include the source files in your C projects.

```bash
git clone https://github.com/yourusername/libft.git
```

### Compilation

The library can be compiled using `make`. To build the library, simply run:

```bash
make
```

This will create a static library file (`libft.a`). To clean up the compiled files, run:

```bash
make clean
```

For a complete cleanup, including the object files, use:

```bash
make fclean
```

To recompile and create the library from scratch, run:

```bash
make re
```

### Usage

Once compiled, you can link the `libft.a` static library in your C project:

```bash
gcc -o your_program your_program.c -L. -lft
```

### Example Usage

```c
#include "libft.h"

int main() {
    char *str = "Hello, World!";
    ft_putstr(str);  // Print string using custom putstr
    return 0;
}
```

## Contributing

Contributions are welcome! If you would like to improve the library or add new functions, feel free to open a pull request.

### Steps to contribute:
1. Fork the repository.
2. Create a new branch for your feature/bugfix.
3. Commit your changes.
4. Push to your fork and create a pull request.

## License

This project is open-source and available under the MIT License.

---

Feel free to modify any sections based on your specific project needs!
