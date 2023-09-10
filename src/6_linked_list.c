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

static Node* add_rec (Node* node, int value) {
    if (node->next_node != NULL) return add_rec(node->next_node, value);
    Node* next_node = malloc(sizeof(Node));
    next_node->previous_node = node;
    next_node->value = value;
    node->next_node = next_node;
    return next_node;
}

static int add (LinkedList* linked_list, int value) {
    if (linked_list->first_node != NULL) {
        Node* last_node = add_rec(linked_list->first_node, value);
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

static void print_rec (Node* node) {
    printf("print_rec: %d\n", node->value);
    if (node->next_node != NULL) print_rec(node->next_node);
}

static void print (LinkedList* linked_list) {
    printf("LinkedList:\n");
    if (linked_list->first_node != NULL) print_rec(linked_list->first_node);
}

static void free_rec (Node* node) {
    if (node->next_node != NULL) free_rec(node->next_node);
    free(node);
}

static void free_linked_list (LinkedList* linked_list) {
    if (linked_list->first_node == NULL) return;
    free_rec(linked_list->first_node);
    free(linked_list);
}

int main () {
    LinkedList* linked_list = malloc(sizeof(LinkedList));

    for (int i = 1; i < 5; i++) {
        printf("adding: %d\n", i);
        add(linked_list, i);
    }

    print(linked_list);

    free_linked_list(linked_list);

    return 0;

}
