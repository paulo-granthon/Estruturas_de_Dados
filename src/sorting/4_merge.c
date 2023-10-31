// Merge sorting algorithm
// best case: O(n log n)
// worst case: O(n log n)

#include <stdio.h>
#include "../utils/array_utils.h"

void sort_merge (int* array, int target_start, int target_end) {
    int half = target_end / 2;
    if (target_end - target_start > 2) {
        sort_merge(array, target_start, half);
        sort_merge(array, half, target_end);
    }
    int i = target_start;
    int j = half;
    int temp = 0;
    while (i < half || j < target_end) {
        printf(
            "s: %d | e: %d\ni: %d | j: %d\n",
            target_start, target_end, i, j
        );
        if (array[j] >= array[i]) {
            printf("skipping... j: %d\n", j + 1);
            j++;
            continue;
        }
        printf("swapping...\n");
        temp = array[i];
        array[i] = array[j];
        array[j] = array[i];
        i++;
        j++;
    }
}

int main () {

    int* array = array_create(10);
    array_print(array, 10);

    sort_merge(array, 0, 10);

    array_print(array, 10);
}
