#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
Stack* create_stack(int capacity){
    Stack* stack = malloc(sizeof(Stack));
    if(!stack){ return NULL;}
    stack->data = malloc(capacity * sizeof(int));
    if(!stack->data) {
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}
void push(Stack* stack, int value){
    if(stack->top == stack->capacity - 1){
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
    
}
int pop(Stack* stack){
    if(stack->top == -1){
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}
void free_stack(Stack* stack){
    if(stack){
        free(stack->data);
        free(stack);
    }
}