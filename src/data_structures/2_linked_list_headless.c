#include <stdio.h>
#include <stdlib.h>
#include "../utils/error_codes.h"
#include "../utils/operation_codes.h"
#include "linked_list_headless.h"


Headless* headless_create(int value, Headless* next) {
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
    h->next = headless_create(value, NULL);
    return OK;
}

int headless_insert (Headless** h, int value, int i) {
    if (i > 0) return (*h)->next != NULL ? headless_insert(&((*h)->next), value, i - 1)
        : i == 1 ? headless_add(*h, value)
            : OUT_OF_BOUNDS;
    Headless* new_h = headless_create(value, *h);
    *h = new_h;
    return OK;
}

Headless* headless_find_previous(Headless* wanted, Headless* h) {
    return h->next == wanted ? h : headless_find_previous(h->next, wanted);
}

int headless_remove(Headless** h) {
    if (h == NULL || *h == NULL) return OUT_OF_BOUNDS;
    Headless* new_h = (*h)->next;
    free(*h);
    *h = new_h;
    return OK;
}

int headless_remove_at (Headless* h, int i) {
    if (i > 0)
        return h->next == NULL ? OUT_OF_BOUNDS
        : headless_remove_at(h->next, i - 1);
    return headless_remove(&h);
}

int headless_index_of (Headless* h, int value, int i) {
    return h->value == value ? i
        : h->next == NULL ? OUT_OF_BOUNDS
            : headless_index_of(h->next, value, i + 1);
}

int headless_contains (Headless* h, int value) {
    return headless_index_of(h, value, 0) == OUT_OF_BOUNDS ? 0 : 1;
}

void headless_print (Headless* h) {
    printf("%d%s", h->value, h->next == NULL ? "}\n" : ", ");
    if (h->next != NULL) headless_print(h->next);
}

void test_operation_proccess_result (int operation, int result, int value, int position) {
    if (result != 0) printf(
        "%s Error in operation %s | value: %d | position: %d. ",
        error_to_string(result), operation_to_string(operation), value, position
    );
}

void test_operation (int operation, int length, int value, int position) {
    printf(
        "\nTESTING OPERATION %s -- | length: %d | value: %d | position: %d\n",
        operation_to_string(operation), length, value, position
    );
    Headless* h = headless_create(10, NULL);
    for (int i = 2; i < length; i++) {
        headless_add(h, i * 10);
    }
    printf("Headless: {");
    headless_print(h);
    switch (operation) {
        case OPERATION_INSERT:
            test_operation_proccess_result(operation, headless_insert(&h, value, position), value, position);
            break;
        case OPERATION_REMOVE:
            test_operation_proccess_result(operation, headless_remove_at(h, position), 0, position);
            break;
        case OPERATION_CONTAINS:
            headless_contains(h, value) == 0 ? printf("YES\n") : printf("NO\n");
            return;
        case OPERATION_INDEX_OF:
            printf("%d\n", headless_index_of(h, value, 0));
            return;
    }
    printf("Headless: {");
    headless_print(h);
}


int main () {

    test_operation(OPERATION_REMOVE, 5, 00, 0);
    test_operation(OPERATION_REMOVE, 5, 00, 1);
    test_operation(OPERATION_REMOVE, 5, 10, 2);
    test_operation(OPERATION_REMOVE, 5, 20, 3);

    return OK;
}
