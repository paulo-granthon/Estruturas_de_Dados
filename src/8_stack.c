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


Stack* stack_create () {
    Stack* stack = malloc(sizeof(Stack));
    stack->data = malloc(sizeof(int) * MIN_SIZE);
    stack->capacity = MIN_SIZE;
    stack->top = -1;
    return stack;
}


void stack_double (Stack* stack) {
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

void stack_halve (Stack* stack) {
    int* new_data = malloc(sizeof(int) * stack->capacity / 2);
    if (new_data == NULL) {
        printf("Error resizing the stack from %d to %d capacity\n", stack->capacity, stack->capacity / 2);
        exit(MALLOC_FAILURE);
    }
    for (int i = 0; i < stack->capacity / 2; i++) {
        new_data[i] = stack->data[i];
    }
    stack->data = new_data;
    stack->capacity = stack->capacity / 2;
}

void stack_push (Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) stack_double(stack);
    stack->top++;
    stack->data[stack->top] = value;
}

int stack_pop (Stack* stack) {
    int value = stack->data[stack->top];
    stack->top--;
    if (stack->top <= stack->capacity / 2) stack_halve(stack);
    return value;
}

void stack_print(Stack* stack) {
    printf("Stack {");
    if (stack->top >= 0) {
        for (int i = 0; i < stack->top; i++) {
            printf("%d, ", stack->data[i]);
        }
        printf("%d", stack->data[stack->top]);
    }
    printf("} (+%d empty)\n", stack->capacity - 1 - stack->top);
}


void test_operation (int operation, int length, int value) {
    printf(
        "\nTESTING OPERATION %s -- | value: %d\n",
        operation_to_string(operation), value
    );
    Stack* stack = stack_create();
    for (int i = 0; i < length; i++) {
        stack_push(stack, (i + 1) * 10);
    }
    stack_print(stack);
    switch (operation) {
        case OPERATION_INSERT:
            stack_push(stack, value);
            break;
        case OPERATION_REMOVE:
            printf("%d\n", stack_pop(stack));
            break;
    }
    stack_print(stack);
}


int main () {
    Stack* stack = stack_create();
    test_operation(OPERATION_INSERT, 0, 999);
    test_operation(OPERATION_INSERT, 15, 999);
    test_operation(OPERATION_INSERT, 16, 999);
}
