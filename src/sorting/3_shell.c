// Shell sort algorithm
// best case: O(n log n)
// worts case: O(n²)

#include <stdio.h>
#include "../utils/array_utils.h"

void sort_shell (int* array, int size) {
    for (int i = 0; i < size; i++) {
        int value_to_swap = array[i];
        int j = i;
        while (j > 0  && value_to_swap < array[j - 1]) {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = value_to_swap;
    }
}

int main () {
    int* array = array_create(10);
    array_print(array, 10);

    sort_shell(array, 10);

    array_print(array, 10);
}
