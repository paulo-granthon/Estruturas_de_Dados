// Selection sorting algorithm
// best case: O(n²) comparisions, O(1) swaps
// worst case: O(n²) comparisions, O(n) swaps

#include<stdio.h>
#include<stdlib.h>

#define RMIN 1
#define RMAX 100

int* array_create (int size) {
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (RMAX - RMIN) + RMIN;
    }
    return array;
}

void array_sort (int* array, int size) {
    for (int i = 0; i < size; i++) {
        int value_to_swap = array[0];
        int target_j = 0;
        for (int j = 0; j < size - i + 1; j++) {
            if (array[j] <= value_to_swap) continue;
            value_to_swap = array[j];
            target_j = j;
        }
        array[target_j] = array[size - i];
        array[size - i] = value_to_swap;
    }
}

void array_print(int* array, int size) {
    printf("array {%d", array[0]);
    for (int i = 1; i < size; i++) {
        printf(", %d", array[i]);
    }
    printf("}\n");
}

int main () {

    int* array = array_create(10);
    array_print(array, 10);

    array_sort(array, 10);

    array_print(array, 10);
}
