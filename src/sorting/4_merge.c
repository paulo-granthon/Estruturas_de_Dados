// Merge sorting algorithm
// best case: O(n log n)
// worst case: O(n log n)

#include <stdio.h>
#include "../utils/array_utils.h"

// void fake_indent(int indent) {
//     for (int i = 0; i < indent; i++) printf("| ");
// }

void sort_merge_combine (int* array, int target_start, int target_end, int indent) {
    int half = (target_end - target_start) / 2;
    int i = target_start;
    int j = target_start + half;
    int temp = 0;

    // fake_indent(indent); printf("combining | target_start: %d | target_end: %d\n", target_start, target_end);

    while (i < target_start + half && j < target_end) {

        // printf("i: [%d]%02d | j: [%d]%02d |=> ", i, array[i], j, array[j]);

        if (array[j] >= array[i]) {
            printf("SKIP...\n");

            j++;
            continue;
        }

        // printf("!SWAP!\n");

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        // printf("i: [%d]%02d | j: [%d]%02d\n", i, array[i], j, array[j]);

        // fake_indent(indent); array_print_slice(array, target_start, target_end);
        i++;
    }
}

void sort_merge (int* array, int target_start, int target_end, int indent) {
    int half = (target_end - target_start) / 2;
    // fake_indent(indent); printf("sort_merge | ts: %d | te: %d | half: %d\n", target_start, target_end, half);
    // fake_indent(indent); printf("input: "); array_print_slice(array, target_start, target_end);

    if (target_end - target_start > 2) {
        sort_merge(array, target_start, target_start + half, indent + 1);
        sort_merge(array, target_start + half, target_end, indent + 1);
    }
    sort_merge_combine(array, target_start, target_end, indent);
    // fake_indent(indent); printf("output: "); array_print_slice(array, target_start, target_end);
}

int main () {

    int len = 3;
    int* array = array_create_desc(len);
    int* copy = array_copy(array, len);

    printf("\nSTART:\n");
    array_print(array, len);
    printf("\n");

    sort_merge(array, 0, len, 0);

    printf("\nRESULT:\n");
    array_print(array, len);
}
