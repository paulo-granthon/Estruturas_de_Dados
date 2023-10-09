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

Node* node_create(int value, Node* previous_node, Node* next_node);

Node* node_add (Node* node, int value);

int node_insert_from_head(Node* node, int value, int position, int current_position);
int node_insert_from_tail(Node* node, int value, int position, int current_position);

void node_print (Node* node);
int node_index_of (Node* node, int value, int current_position);

int node_remove_at_from_head(Node* node, int position, int current_position);
int node_remove_at_from_tail(Node* node, int position, int current_position);

void node_free_recursive (Node* node);

int linked_list_add (LinkedList* linked_list, int value);
int linked_list_insert (LinkedList* linked_list, int value, int position);

void linked_list_print (LinkedList* linked_list);

int linked_list_index_of (LinkedList* linked_list, int value);
int linked_list_contains (LinkedList* linked_list, int value);

int linked_list_remove_at (LinkedList* linked_list, int position);

void linked_list_clear (LinkedList* linked_list);
void linked_list_free (LinkedList* linked_list);
