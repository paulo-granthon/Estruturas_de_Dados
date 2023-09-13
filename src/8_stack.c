#include <stdio.h>
#include <stdlib.h>
#include "./utils/error_codes.h"
#include "./utils/operation_codes.h"

#define MIN_SIZE 16


typedef struct Stack {
    int* data;
    int capacity;
    int top;
} Stack;


// first in first out 
Stack* stack_create () {
    Stack* stack = malloc(sizeof(Stack));
    stack->data = malloc(sizeof(int) * MIN_SIZE);
    stack->capacity = MIN_SIZE;
    stack->top = -1;
    return stack;
}


void stack_resize (Stack* stack) {
    int* new_data = malloc(sizeof(int) * stack->capacity * 2);
    if (new_data == NULL) {
        printf("Error resizing the stack from %d to %d capacity\n", stack->capacity, stack->capacity * 2);
        exit(MALLOC_FAILURE);
    }
    for (int i = 0; i < stack->capacity; i++) {
        new_data[i] = stack->data[i];
    }
    stack->data = new_data;
    stack->capacity = stack->capacity * 2;
}

void stack_push (Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) stack_resize(stack);
    stack->top++;
    stack->data[stack->top] = value;
}

// pop
