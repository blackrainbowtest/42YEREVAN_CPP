# **C++ Module 07 - Templated Classes and Functions**

## **Overview**

This repository contains the implementations for Module 07 of the 42 School's C++ curriculum, focusing on the use of templated classes and functions. C++ templates allow for generic programming, enabling functions and classes to operate with any data type without being specifically tailored for each one.

# **Status**

Validated on 21/02/2024. Grade: 100%.

## **General Information**

- **Compiler used:** **`c++`**
- **Compilation flags:** **`Wall -Wextra -Werror -std=c++98`**
- **Standard:** C++98 for compliance and simplicity, per the 42 School curriculum's requirements.

## **Projects**

This module is divided into three exercises, each emphasizing different aspects of C++ templated programming.

### **Exercise 00: Start with a few functions**

- **Directory:** **`ex00/`**
- **Files:** **`Makefile`**, **`main.cpp`**, **`whatever.hpp`**
- **Description:** Implement templated functions **`swap`**, **`min`**, and **`max`** that can operate on any data type supporting comparison operations.
- **Key Concepts:** Templated functions, Type agnosticism, Comparison operators.

### **Exercise 01: Iter**

- **Directory:** **`ex01/`**
- **Files:** **`Makefile`**, **`main.cpp`**, **`iter.hpp`**
- **Description:** Create a templated function **`iter`** that applies a given function to every element of an array of any data type.
- **Key Concepts:** Templated functions, Function pointers as arguments, Arrays manipulation, Type abstraction.

### **Exercise 02: Array**

- **Directory:** **`ex02/`**
- **Files:** **`Makefile`**, **`main.cpp`**, **`Array.hpp`**, (optional) **`Array.tpp`**
- **Objective:** Develop a templated class **`Array`** that encapsulates an array of any type, with dynamic sizing, element access, and deep copying. This exercise aims to demonstrate the utility of templates in creating versatile data structures. The **`Array`** class should manage memory carefully to avoid leaks and should throw an exception for out-of-bounds access attempts, ensuring safe and flexible array manipulation.
- **Key Concepts:** Templated classes, Memory management, Operator overloading, Exception handling.

## **Compilation and Usage**

Each exercise comes with a **`Makefile`** facilitating the compilation process. Use the following **`make`** commands to compile and clean each project:

Each exercise directory contains a Makefile for easy compilation. To compile an exercise, navigate to its directory and run:

After compilation, an executable named after the exercise (e.g., **`ex00`**, **`ex01`**, **`ex02`**) will be created. Run it with **`./[executable name]`** to see the functionality of the implemented templates.

For example :

```bash
cd ex00 && make && ./ex00
```