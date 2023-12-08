#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

int* array_create (int size) {
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (RMAX - RMIN) + RMIN;
    }
    return array;
}

int* array_create_desc (int size) {
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = size - i;
    }
    return array;
}

void array_print(int* array, int size) {
    printf("array {%d", array[0]);
    for (int i = 1; i < size; i++) {
        printf(", %d", array[i]);
    }
    printf("}\n");
}

void array_print_slice(int* array, int start, int end) {
    printf("array {%d", array[start]);
    for (int i = start + 1; i < end; i++) {
        printf(", %d", array[i]);
    }
    printf("}\n");
}

int* array_copy (int* array, int size) {
    int* copy = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        copy[i] = array[i];
    }
    return copy;
}
