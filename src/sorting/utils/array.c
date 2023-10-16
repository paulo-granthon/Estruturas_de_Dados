#include<stdio.h>
#include<stdlib.h>
#include"array.h"

int* array_create (int size) {
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (RMAX - RMIN) + RMIN;
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
