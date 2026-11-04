*This project has been created as part of the 42 curriculum by oaljausi.*

# ft_printf

## Description
The goal of this project is to recreate the standard C `printf()` function. It supports formatted output using conversion specifiers such as `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

## Instructions

Compile the library:

```bash
make
```

Compile your program:

```bash
cc main.c -L. -lftprintf
```

Include the header:

```c
#include "ft_printf.h"
```

## Resources
- `printf(3)` and `stdarg(3)` manual pages.
- https://en.cppreference.com/w/c
- https://www.gnu.org/software/libc/manual/

### AI Usage
AI was used to help understand variadic functions, format specifiers, debugging, and documentation. The code should be tested and understood by the student.
## Additional section
## Algorithm and Data Structures
The function processes the format string character by character. When it encounters `%`, it identifies the conversion specifier and calls the appropriate function. A counter tracks the number of printed characters and is returned at the end.

The implementation uses a format string, `va_list` to access variable arguments, and an integer counter. These choices keep the implementation simple and efficient.

