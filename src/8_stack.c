#include <stdio.h>
#include <stdlib.h>

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

// resize

// push

// pop
