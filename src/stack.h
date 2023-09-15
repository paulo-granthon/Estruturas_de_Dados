typedef struct Stack {
    int* data;
    int capacity;
    int top;
} Stack;

Stack* stack_create ();

void stack_double (Stack* stack);
void stack_halve (Stack* stack);

void stack_push (Stack* stack, int value);

int stack_pop (Stack* stack);

int* stack_index_of (Stack* stack, int value);
int stack_contains (Stack* stack, int value);

void stack_print(Stack* stack);
