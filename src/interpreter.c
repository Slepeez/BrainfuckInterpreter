#include "interpreter.h"
int* precompute_jumps(const char* code, size_t code_length){
    int* jumps = malloc(code_length * sizeof(int));

    Stack * stack = create_stack(code_length);
    if(!stack || !jumps){
        fprintf(stderr, "Failed to allocate memory\n");
        free_stack(stack);
        free(jumps);
        exit(EXIT_FAILURE);
    }
    for(size_t i =  0; i < code_length; i++){
        jumps[i] = -1;
        if(code[i] == '['){
            push(stack, i);
        } else if(code[i] == ']'){
            if(stack->top == -1){
                fprintf(stderr, "Unmatched ']' at position %d\n", i);
                free_stack(stack);
                free(jumps);
                exit(EXIT_FAILURE);
            }
            int open_pos = pop(stack);
            jumps[i] = open_pos;
            jumps[open_pos] = i;
        }
    }
    free_stack(stack);
    return jumps;
}
void interpret(const char* code, size_t code_length){
    unsigned char tape[TAPE_SIZE] = {0};
    unsigned char *ptr = tape;
    int* jumps = precompute_jumps(code, code_length);
    size_t code_program_counter = 0;
    while(code_program_counter < code_length){
        switch(code[code_program_counter]){
            case '>':
                if(ptr == tape + TAPE_SIZE - 1){
                    fprintf(stderr, "Pointer overflow\n");
                    free(jumps);
                    exit(EXIT_FAILURE);
                }
                ptr++;
                break;
            case '<':
                if(ptr <= tape){
                    fprintf(stderr, "Pointer underflow\n");
                    free(jumps);
                    exit(EXIT_FAILURE);
                }
                ptr--;
                break;
            case '+':
                (*ptr)++;
                break;
            case '-':
                (*ptr)--;
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if(*ptr == 0){
                    code_program_counter = jumps[code_program_counter];
                }
                break;
            case ']':
                if(*ptr != 0){
                    code_program_counter = jumps[code_program_counter];
                }
                break;
            default:
                break;
        }
        code_program_counter++;
    }
    free(jumps);
}
