# ylib
ylib is an alternative to libft.

Libft is a C library that is used in 42 School and developed by its students. ylib aims to be a simple alternative that provides a variety of useful types and functions to simplify the development of 42 School projects. ylib is compatible with 42 School Norm v3*.

*My definition of "compatible" is that the norminette doesn't complain about the code :).

## What's new
### 1.1
* Added initializers and deinitializers for lists and strings.
* Added string and cstring formatting.
### 1.0
* Initial release.


# Modules
ylib is split into several modules (.h files), each one of them can be used on its own, but may depend on other modules (i.e. almost every module depends on ytypes.h). To include every module, use:
`#import <ylib.h>`.
To avoid potential name clashes, it is recomended to only include ytypes.h in other header files.

## Headers
- `ylib.h` - includes everything from the library.
- `ydefines.h` - currently only contains an alternative definition for NULL.
- `ytypes.h` - contains all types declarations of ylib.
- `ychar.h` - contains various character related functions.
- `ycmem.h` - contains functions for performing raw memory operations.
- `ycstr.h` - contains functions for manipulating character arrays (cstrings).
- `yio.h` - contains functions for reading/writing cstrings to file descriptors.
- `ylist.h` - contains various functions for managing untyped, dynamically-sized lists of pointers.
- `ymath.h` - contains various math functions that I've found to be useful in situations where the use of math.h was prohibited/wasn't enough.
- `yprint.h` - contains yprintf - an alternative to printf for cases when printf is not allowed.
- `yprint_format.h` - is for internal use only. Do not include it in your projects. It contains helper functions for yprintf formatting.
- `ystring.h` - contains functions for manipulating strings. Strings are an alternative to cstrings that contain both cstring itself and its length. They were developed for a scenario where the support of various UTF encodings was necessary, however I haven't encountered such projects yet.
- `yvec2.h` - contains operations for 2D vectors of ints and doubles.
