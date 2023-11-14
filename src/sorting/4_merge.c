// Merge sorting algorithm
// best case: O(n log n)
// worst case: O(n log n)

#include <stdio.h>
#include "../utils/array_utils.h"

void fake_indent(int indent) {
    for (int i = 0; i < indent; i++) printf("| ");
}

void sort_merge (int* array, int target_start, int target_end, int indent) {
    int half = (target_end - target_start) / 2;
    fake_indent(indent); printf("sort_merge | ts: %d | te: %d | half: %d\n", target_start, target_end, half);
    fake_indent(indent); printf("input: ");
    array_print_slice(array, target_start, target_end);
    if (target_end - target_start > 2) {
        sort_merge(array, target_start, target_start + half, indent + 1);
        sort_merge(array, target_start + half, target_end, indent + 1);
    }
    int i = target_start;
    int j = half;
    int temp = 0;
    while (i < half && j < target_end) {
        // printf( "s: %d | e: %d | i: [%d]%02d >=? j: [%d]%02d || ", target_start, target_end, i, array[i], j, array[j]);
        if (array[j] >= array[i]) {
            // printf("SKIP...\n");
            j++;
            continue;
        }
        // printf("!SWAP!\n");
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
    }
    fake_indent(indent); printf("output: ");
    array_print_slice(array, target_start, target_end);
}

int main () {

    int* array = array_create(10);
    int* copy = array_copy(array, 10);
    array_print(array, 10);

    sort_merge(array, 0, 10, 0);

    printf("\nRESULT:\n");
    array_print(copy, 10);
    printf("   __\n  |  |\n  |  |\n _|  |_\n \\    /\n  \\  /\n   \\/\n");
    array_print(array, 10);
}
