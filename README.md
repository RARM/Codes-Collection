# Codes Collection
This repository's purpose is to keep small programs in C and C++ (and probably Assembly in the future) that serve as examples for certain functionalities or algorithms.

## How to Use Programs
Read the complete list of programs and descriptions [here](list.md). Once you find a  program that interests you, you can read through it or compile it to try. Programs only need the GNU Compiler (`gcc` for C and `g++` for C++).

Assume all programs comply with the following:
1. They are cross-platform (work on Windows, Linux, and macOS).
1. They do not require anything other than the standard libraries. You only need to compile a single file (no custom headers or other C/C++ files).
1. They do not require any arguments but run programs through the terminal. Some programs may not run correctly if you double click on the compiled program.
1. To compile, just run `gcc -o <output_file> <source_code>` (use `g++` for C++ programs instead of the `gcc`). No other flags are required.

If one program does not comply with these points (e.g., it requires other flags during compilation), that should be clear in a comment at the beginning of the source code.

Inline comments are good practice. You may find comments in complicated algorithms or to clarify the purpose of a function. There will be also questions at the end of or through the source code to make the reader think about how to improve the code.

### Example
Let's say you want to try the [dynamic_arr](C/dynamic_arr.c) C program. You need to have the GNU GCC (since this is a C program) installed. Download the source code, and run the following command (in the same folder where the source code is located) to compile:
```bash
gcc -o dynamic_arr dynamic_arr.c
```

If you want to run the program of the example above, just enter in your terminal:
```
./dynamic_arr
```

### Audience
These small example programs are helpful for new programmers and experienced ones. **New programmers** may just follow the code and Google any unknown functions to learn, and I strongly suggest practicing coding a different version of these programs from scratch. Some programs may have less than 20 lines of code, while others much more than 200; be patient while learning.

If you are an **experienced programmer**, these example programs may just help as a reminder of how to do certain things. For example, the `dirc.c` program may help you reminding you how to read files in a directory.

_**Can I use these source codes in my programs?**_

## License
In simple words, you are free to use these source codes (no need to attribute or add any copyright notices), but they are provided "as is". This means, neither I nor contributors are responsible for the effects of using these programs, source codes, or portions of the same.

All programs in this repository are under [this license](UNLICENSE) (unlicensed). You can read it. It is very short.

Although you are not required to attribute, I would love to see if you have done something with these source codes (e.g., you used these in a How-To website). Feel free to email me (find my email in [my GitHub profile](https://github.com/RARM)).

# Contribute
If you want to add your program to this repository, improve a source code (for example, to comply with C and C++ standards), point any errors, improve documentation (for example, organizing the list of programs and descriptions), that is very much appreciated. Please, refer to the [CONTRIBUTING.md](CONTRIBUTING.md) file.
