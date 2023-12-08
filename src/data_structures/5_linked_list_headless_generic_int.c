#include <stdio.h>
#include <stdlib.h>
#include "../utils/error_codes.h"
#include "../utils/operation_codes.h"
#include "linked_list_headless_generic.c"

DECLARE_HEADLESS_TYPE(Headless, int);
IMPLEMENT_HEADLESS_FUNCTIONS(Headless, int);
IMPLEMENT_HEADLESS_PRINT(Headless, int);

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
    Headless* h = Headless_create(10, NULL);
    for (int i = 2; i < length; i++) {
        Headless_add(h, i * 10);
    }
    printf("Headless: {");
    Headless_print(h);
    switch (operation) {
        case OPERATION_INSERT:
            test_operation_proccess_result(operation, Headless_insert(&h, value, position), value, position);
            break;
        case OPERATION_REMOVE:
            test_operation_proccess_result(operation, Headless_remove_at(&h, position), 0, position);
            break;
        case OPERATION_CONTAINS:
            Headless_contains(h, value) == 0 ? printf("YES\n") : printf("NO\n");
            return;
        case OPERATION_INDEX_OF:
            printf("%d\n", Headless_index_of(h, value, 0));
            return;
    }
    printf("Headless: {");
    Headless_print(h);
}


int main () {

    test_operation(OPERATION_INSERT, 5, 0, 0);
    test_operation(OPERATION_INSERT, 5, 0, 1);
    test_operation(OPERATION_INSERT, 5, 0, 2);
    test_operation(OPERATION_INSERT, 5, 0, 3);

    test_operation(OPERATION_REMOVE, 5, 0, 0);
    test_operation(OPERATION_REMOVE, 5, 0, 1);
    test_operation(OPERATION_REMOVE, 5, 0, 2);
    test_operation(OPERATION_REMOVE, 5, 0, 3);

    return OK;
}
