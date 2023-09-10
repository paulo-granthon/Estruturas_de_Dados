#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    struct Node* next_node;
    struct Node* previous_node;
    int value;
} Node;


typedef struct LinkedList {
    struct Node* first_node;
    struct Node* last_node;
    int length;
} LinkedList;


Node* node_add (Node* node, int value) {
    if (node->next_node != NULL) return node_add(node->next_node, value);
    Node* new_node = malloc(sizeof(Node));
    new_node->previous_node = node;
    node->next_node = new_node;
    new_node->next_node = NULL;
    new_node->value = value;
    return new_node;
}

int linked_list_add (LinkedList* linked_list, int value) {
    if (linked_list->first_node != NULL) {
        Node* last_node = node_add(linked_list->first_node, value);
        if (last_node == NULL) return 1;
        linked_list->last_node = last_node;
        linked_list->length++;
        return 0;
    }
    Node* first_node = malloc(sizeof(Node));
    first_node->value = value;
    linked_list->first_node = first_node;
    linked_list->last_node = first_node;
    linked_list->length++;
    return 0;
}

void node_print (Node* node) {
    printf("%d%s", node->value, node->next_node != NULL ? ", " : "");
    if (node->next_node != NULL) node_print(node->next_node);
}

void linked_list_print (LinkedList* linked_list) {
    printf("LinkedList {");
    if (linked_list->first_node != NULL) node_print(linked_list->first_node);
    printf("}\n");
}

void node_free (Node* node) {
    if (node->next_node != NULL) node_free(node->next_node);
    free(node);
}

void linked_list_free (LinkedList* linked_list) {
    if (linked_list->first_node == NULL) return;
    node_free(linked_list->first_node);
    free(linked_list);
}

int main () {
    LinkedList* linked_list = malloc(sizeof(LinkedList));
    linked_list->length = 0;

    for (int i = 1; i < 5; i++) {
        printf("adding: %d\n", i);
        linked_list_add(linked_list, i);
    }

    linked_list_print(linked_list);

    linked_list_free(linked_list);

    return 0;

}
