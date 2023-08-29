#include <stdio.h>


typedef struct Node {
    struct Node* next_node;
    struct Node* previous_node;
    int value;
} Node;


typedef struct LinkedList {
    struct Node* first_node;
} LinkedList;


static int add_rec (Node* node, int value) {
    if (node->next_node != NULL) return add_rec(node->next_node, value);
    node->next_node = &(Node){
        .next_node = NULL,
        .previous_node = node,
        .value = value
    };
    return 0;
}

static int add (LinkedList* linked_list, int value) {
    if (linked_list->first_node != NULL) return add_rec(linked_list->first_node, value);
    linked_list->first_node = &(Node){
        .next_node = NULL,
        .previous_node = NULL,
        .value = value
    };
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

int main () {
    LinkedList linked_list = (LinkedList){};

    for (int i = 0; i < 5; i++) {
        printf("adding: %d\n", i);
        add(&linked_list, i);

    }

    print(&linked_list);

    return 0;

}
