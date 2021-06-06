# List of programs

**C Programs**:
* [dynamic_arr.c](#--dynamic-array)

**C++ Programs**:
* [dynamic_list.cpp](#--dynamic-list)
* [verify_numeric_input.cpp](#--verify-numeric-input)

---
## C Programs

##### - Dynamic Array
This is a small program that allows you to make a list of integers and get the average. The array that holds the list of integers is allocated dynamically (using `malloc`, `calloc`, `relloc`, and `free` functions). [View the source code](C/dynamic_arr.c).

---
## C++ Programs

##### - Dynamic List
Like the C program, [Dynamic Array](#dynamic-array), this program also allows you to make a dynamic list of integers. However, the dynamic list is created and managed using the `<vector>` class. This C++ program is a much simpler solution. [View the source code](C++/dynamic_list.cpp).

##### - Verify Numeric Input
This program asks for a list of numbers (separated by white space) and verifies that those are actual numbers and not words. The highlighted function of this program is `is_numeric_input`. The function allows you to verify integers and floats. [View source code](C++/verify_numeric_input.cpp).
