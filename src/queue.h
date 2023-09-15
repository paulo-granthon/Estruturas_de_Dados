typedef struct Queue {
    int* data;
    int capacity;
    int head;
    int tail;
} Queue;

Queue* queue_create ();

void queue_double (Queue* queue);
void queue_reduce (Queue* queue);

void queue_push (Queue* queue, int value);

int queue_pop (Queue* queue);

void queue_print(Queue* queue);
