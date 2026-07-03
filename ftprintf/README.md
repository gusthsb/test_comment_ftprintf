## Author

*This project has been created as part
of the 42 curriculum by gustde-s*

# Description - ft_printf

The `ft_printf` project is a re-implementation of the standard C library `printf` function. It parses a format string and handles variable arguments using `va_list`, outputting the formatted result to the standard output. This project provides a deep dive into variadic functions in C and a deep understanding of the printf function itself.

## Functions

| Function | Description |
|:---:|---|
| `%c`| Prints a single character.|
| `%s`| Prints a string.|
| `%p`| Prints a `void *` pointer argument in hexadecimal format.|
| `%d`| Prints a decimal (base 10) number.|
| `%i`| Prints an integer in base 10.|
| `%u`| Prints an unsigned decimal (base 10) number.|
| `%x`| Prints a number in hexadecimal (base 16) in lowercase format.|
| `%X`| Prints a number in hexadecimal (base 16) in uppercase format.|
| `%%`| Prints a percent sign.|

## Usage

### Compilation
To compile the library, run the following commands at the root of repository:
```bash
make        # compile the functions
make clean  # remove object files
make fclean # remove object files and the library
make re     # recompile everything
```

## Resources

- https://www.geeksforgeeks.org/c/printf-in-c/
- Ft_printf 42 subject

AI tools (Gemini and Claude) were used to better understand concepts such as va_lists, as well as to clarify errors and misunderstandings. In more challenging cases, the Socratic method was used to guide the reasoning process rather than receive direct answers.