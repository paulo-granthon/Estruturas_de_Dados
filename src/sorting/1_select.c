// Selection sorting algorithm
// best case: O(n²) comparisions, O(1) swaps
// worst case: O(n²) comparisions, O(n) swaps

#include <stdio.h>
#include "../utils/array_utils.h"

void sort_select (int* array, int size) {
    for (int i = size - 1; i >= 0; i--) {
        int value_to_swap = array[0];
        int target_j = 0;
        for (int j = 0; j < i + 1; j++) {
            if (array[j] <= value_to_swap) continue;
            value_to_swap = array[j];
            target_j = j;
        }
        array[target_j] = array[i];
        array[i] = value_to_swap;
    }
}

int main () {

    int* array = array_create(10);
    array_print(array, 10);

    sort_select(array, 10);

    array_print(array, 10);
}
