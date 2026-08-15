
cmake_minimum_required(VERSION 3.10)

project(BrainfuckInterpreter C)


set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)


if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -O3)
endif()


add_executable(brainfuck_interpreter
    src/interpreter.c 
    src/stack.c
    src/main.c
)
