#ifndef INTERPRETER_H
#define INTERPRETER_H
#define TAPE_SIZE 30000
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int* precompute_jumps(const char* code, size_t code_length);
void interpret(const char* code, size_t code_length);

#endif