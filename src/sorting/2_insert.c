// Insertion sorting algorithm
// best case: O(n) comparisons, O(1) swaps
// worst case: O(n²) comparisions and swaps

#include <stdio.h>
#include "../utils/array_utils.h"

void sort_insert (int* array, int size) {
    for (int i = size - 1; i >= 0; i--) {
        for (int j = size - 1 - i; j >= 0; j--) {
            printf("%d\n", array[i]);
        
        }
    }
}

int main () {
    int* array = array_create(10);
    array_print(array, 10);

    sort_insert(array, 10);

    array_print(array, 10);
}
