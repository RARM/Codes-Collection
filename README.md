# Codes Collection
This repository's purpose is to keep small programs in C and C++ (and probably Assembly in the future) that serve as examples for certain functionalities or algorithms.

## How to Use Programs
Read the complete list of programs and descriptions [here](list.md). Once you find a  program that interests you, you can read through it or compile it to try. Programs only need the GNU Compiler (`gcc` for C and `g++` for C++). If a program needs a library or works only on a specific OS, information should be available at the beginning of the source code. Programs, however, will always be single files. This means, you only need to compile that single file to use the program.

For example, let's say you want to try the "dynamic_arr" C program. You need to have the GNU GCC (since this is a C program) installed. Download the source code, and run the following command (in the same folder where the source code is located) to compile:
```bash
gcc -o dynamic_arr dynamic_arr.c
```

Programs will not require arguments unless otherwise specified at the beginning of the source code. If you want to run the program of the example above, just enter in your terminal:
```
./dynamic_arr
```

These small example programs are helpful for new programmers and experienced ones. New programmers may just follow the code and Google any unknown functions to learn, and I strongly suggest that you practice coding a different version of these programs from scratch. Some programs may have less than 20 lines of code, while others much more than 200; be patient while learning.

If you are an experienced programmer, these example programs may just help as a reminder of how to do certain things. For example, the `dirc.c` program may help you reminding you how to read files in a directory.

**Can I use these source codes in my programs?**

## License
In simple words, you are free to use these source codes (no need to attribute or add any copyright notices), but they are provided "as is". This means, neither I nor contributors are responsible for the effects of using these programs, source codes, or portions of the same.

All programs in this repository are under [this license](UNLICENSE) (unlicensed). You can read it. It is very short.

# Contribute
If you want to add your program to this repository, improve a source code (for example, to comply with C and C++ standards), point any errors, improve documentation (for example, organizing the list of programs and descriptions), that is very much appreciated. Please, refer to the [CONTRIBUTING.md](CONTRIBUTING.md) file.
