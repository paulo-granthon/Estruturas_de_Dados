// Selection sorting algorithm
// best case: O(n²) comparisions, O(1) swaps
// worst case: O(n²) comparisions, O(n) swaps

#include"./utils/array.h"

void sort_select (int* array, int size) {
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

int main () {

    int* array = array_create(10);
    array_print(array, 10);

    sort_select(array, 10);

    array_print(array, 10);
}
