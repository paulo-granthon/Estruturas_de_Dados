#include <stdio.h>
#include <stdlib.h>


#define OK 0
#define MALLOC_FAILURE 1
#define OUT_OF_BOUNDS -1
char* error_to_string (int error) {
    switch (error) {
        case OK: return "OK";
        case MALLOC_FAILURE: return "MALLOC_FAILURE";
        case OUT_OF_BOUNDS: return "OUT_OF_BOUNDS";
        default: {
            static char buf[32];
            snprintf(buf, sizeof(buf), "UNKNOWN_ERROR: %d", error);
            return buf;
        }
    }
}


typedef struct Node {
    struct Node* next_node;
    struct Node* previous_node;
    int value;
} Node;


Node* node_create(int value, Node* previous_node, Node* next_node) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Failed to allocate memory for a new Node");
        exit(MALLOC_FAILURE);
    }

    new_node->next_node = next_node;
    if (next_node != NULL) next_node->previous_node = new_node;

    new_node->previous_node = previous_node;
    if (previous_node != NULL) previous_node->next_node = new_node;

    new_node->value = value;
    return new_node;
}

Node* node_add (Node* node, int value) {
    if (node->next_node != NULL) return node_add(node->next_node, value);
    return node_create(value, node, NULL);
}

int node_insert_from_head(Node* node, int value, int position, int current_position) {
    if (current_position != position - 1)
        return node->next_node == NULL ? OUT_OF_BOUNDS
        : node_insert_from_head(node->next_node, value, position, current_position + 1);
    printf("Inserting from head\n");
    node_create(value, node, node->next_node);
    return OK;
}
int node_insert_from_tail(Node* node, int value, int position, int current_position) {
    if (current_position != position)
        return node->previous_node == NULL ? OUT_OF_BOUNDS
        : node_insert_from_tail(node->previous_node, value, position, current_position - 1);
    printf("Inserting from tail\n");
    node_create(value, node->previous_node, node);
    return OK;
}

void node_print (Node* node) {
    printf("%d%s", node->value, node->next_node != NULL ? ", " : "");
    if (node->next_node != NULL) node_print(node->next_node);
}

int node_index_of (Node* node, int value, int current_position) {
    return node->value == value ? current_position
        : node_index_of(node->next_node, value, current_position + 1);
}

int node_remove_at_from_head(Node* node, int position, int current_position) {
    if (current_position != position)
        return node->next_node == NULL ? OUT_OF_BOUNDS
        : node_remove_at_from_head(node->next_node, position, current_position + 1);
    printf("Removing at position %d from head\n", position);
    node->previous_node->next_node = node->next_node;
    node->next_node->previous_node = node->previous_node;
    free(node);
    return OK;
}
int node_remove_at_from_tail(Node* node, int position, int current_position) {
    if (current_position != position)
        return node->previous_node == NULL ? OUT_OF_BOUNDS
        : node_remove_at_from_tail(node->previous_node, position, current_position - 1);
    printf("Removing at position %d from tail\n", position);
    node->previous_node->next_node = node->next_node;
    node->next_node->previous_node = node->previous_node;
    free(node);
    return OK;
}

void node_free_recursive (Node* node) {
    if (node->next_node != NULL) node_free_recursive(node->next_node);
    free(node);
}


typedef struct LinkedList {
    struct Node* first_node;
    struct Node* last_node;
    int length;
} LinkedList;


LinkedList* linked_list_create() {
    LinkedList* linked_list = malloc(sizeof(LinkedList));
    if (linked_list == NULL) {
        perror("Failed to allocate memory for the linked list");
        exit(MALLOC_FAILURE);
    }
    linked_list->first_node = NULL;
    linked_list->last_node = NULL;
    linked_list->length = 0;
    return linked_list;
}

int linked_list_add (LinkedList* linked_list, int value) {
    if (linked_list->last_node != NULL) {
        Node* last_node = node_add(linked_list->last_node, value);
        linked_list->last_node = last_node;
        linked_list->length++;
        return OK;
    }
    Node* first_node = node_create(value, NULL, NULL);
    first_node->value = value;
    linked_list->first_node = first_node;
    linked_list->last_node = first_node;
    linked_list->length++;
    return OK;
}

int linked_list_insert (LinkedList* linked_list, int value, int position) {
    if (position < 0 || position > linked_list->length) return OUT_OF_BOUNDS;
    if (position == 0) {
        linked_list->first_node = node_create(value, NULL, linked_list->first_node);
        return OK;
    }
    if (position == linked_list->length) {
        linked_list->last_node = node_create(value, linked_list->last_node, NULL);
        return OK;
    }
    return position >= linked_list->length / 2 ?
        node_insert_from_tail(linked_list->last_node, value, position, linked_list->length - 1)
        : node_insert_from_head(linked_list->first_node, value, position, 0);
}

void linked_list_print (LinkedList* linked_list) {
    printf("LinkedList {");
    if (linked_list->first_node != NULL) node_print(linked_list->first_node);
    printf("}\n");
}

int linked_list_remove_at (LinkedList* linked_list, int position) {
    if (position < 0 || position >= linked_list->length) return OUT_OF_BOUNDS;
    if (position == 0) {
        linked_list->first_node = linked_list->first_node->next_node;
        free(linked_list->first_node->previous_node);
        linked_list->first_node->previous_node = NULL;
        linked_list->length--;
        return OK;
    }
    if (position == linked_list->length - 1) {
        linked_list->last_node = linked_list->last_node->previous_node;
        free(linked_list->last_node->next_node);
        linked_list->last_node->next_node = NULL;
        linked_list->length--;
        return OK;
    }
    int result = position >= linked_list->length / 2 ?
        node_remove_at_from_tail(linked_list->last_node, position, linked_list->length - 1)
        : node_remove_at_from_head(linked_list->first_node, position, 0);
    if (result == OK) {
        linked_list->length--;
        return OK;
    }
    return result;
}

void linked_list_clear (LinkedList* linked_list) {
    if (linked_list == NULL || linked_list->first_node == NULL) return;
    node_free_recursive(linked_list->first_node);
    linked_list->first_node = NULL;
    linked_list->last_node = NULL;
    linked_list->length = 0;
}

void linked_list_free (LinkedList* linked_list) {
    if (linked_list->first_node == NULL) return;
    node_free_recursive(linked_list->first_node);
    free(linked_list);
}


#define OPERATION_INSERT 0
#define OPERATION_REMOVE_AT 1
char* operation_to_string (int operation) {
    switch (operation) {
        case OPERATION_INSERT: return "OPERATION_INSERT";
        case OPERATION_REMOVE_AT: return "OPERATION_REMOVE_AT:";
        default: {
            static char buf[32];
            snprintf(buf, sizeof(buf), "UNKNOWN_OPERATION: %d", operation);
            return buf;
        }
    }
}


void test_operation (int operation, int length, int value, int position) {
    printf(
        "\nTESTING OPERATION %s -- | length: %d | value: %d | position: %d\n",
        operation_to_string(operation), length, value, position
    );
    LinkedList* linked_list = linked_list_create();
    for (int i = 1; i < length; i++) {
        linked_list_add(linked_list, i * 10);
    }
    linked_list_print(linked_list);
    if (operation == OPERATION_INSERT) {
        int result = linked_list_insert(linked_list, value, position);
        if (result != 0) printf(
            "%s Error inserting value %d at position %d of linked_list with length %d. ",
            error_to_string(result), value, position, linked_list->length
        );
    }
    if (operation == OPERATION_REMOVE_AT) {
        int result = linked_list_remove_at(linked_list, position);
        if (result != 0) printf(
            "%s Error removing value at position %d of linked_list with length %d. ",
            error_to_string(result), position, linked_list->length
        );
    }
    linked_list_print(linked_list);
}


int main () {
    test_operation(OPERATION_REMOVE_AT, 11, 0, 0);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 1);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 2);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 3);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 4);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 5);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 6);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 7);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 8);
    test_operation(OPERATION_REMOVE_AT, 11, 0, 9);

    // test_operation(OPERATION_INSERT, 5, 0, 0);
    // test_operation(OPERATION_INSERT, 5, 0, 1);
    // test_operation(OPERATION_INSERT, 5, 0, 2);
    // test_operation(OPERATION_INSERT, 5, 0, 3);
    // test_operation(OPERATION_INSERT, 5, 0, 4);
    // test_operation(OPERATION_INSERT, 5, 0, 5);
    // test_operation(OPERATION_INSERT, 10, 0, 5);
    // test_operation(OPERATION_INSERT, 10, 0, 4);

    return OK;
}
