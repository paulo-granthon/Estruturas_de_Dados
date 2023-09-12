#include <stdio.h>
#include <stdlib.h>
#include "./utils/error_codes.h"
#include "./utils/operation_codes.h"


typedef struct Headless {
    struct Headless* next;
    int value;
} Headless;


Headless* new_headless(int value, Headless* next) {
    Headless* h = malloc(sizeof(Headless));
    if (h == NULL) {
        perror("Failed to allocate memory for a new Headless");
        exit(MALLOC_FAILURE);
    }
    h->value = value;
    h->next = next;
    return h;
}

int headless_add (Headless* h, int value) {
    if (h->next != NULL) return headless_add(h->next, value);
    h->next = new_headless(value, NULL);
    return OK;
}

int headless_insert (Headless** h, int value, int i) {
    if (i > 0)
        return (*h)->next != NULL ? headless_insert(&((*h)->next), value, i - 1)
        : headless_add(*h, value);
    Headless* new_h = new_headless(value, *h);
    *h = new_h;
    return OK;
}

// remove
// contains
// index_of

void headless_print (Headless* h) {
    printf("%d", h->value);
    if (h->next == NULL) {
        printf("}\n");
        return;
    }
    printf(", ");
    headless_print(h->next);
}


void test_operation (int operation, int length, int value, int position) {
    printf(
        "\nTESTING OPERATION %s -- | length: %d | value: %d | position: %d\n",
        operation_to_string(operation), length, value, position
    );
    Headless* first_cell = new_headless(10, NULL);
    Headless** h = &first_cell;
    for (int i = 2; i < length; i++) {
        headless_add(*h, i * 10);
    }
    printf("Headless: {");
    headless_print(*h);
    if (operation == OPERATION_INSERT) {
        int result = headless_insert(h, value, position);
        if (result != 0) printf(
            "%s Error inserting value %d at position %d. ",
            error_to_string(result), value, position
        );
    }
    printf("Headless: {");
    headless_print(*h);
}
int main () {

    test_operation(0, 5, 999, 0);
    test_operation(0, 5, 999, 1);
    test_operation(0, 5, 999, 2);

    return OK;
}
