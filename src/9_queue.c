#include <stdio.h>
#include <stdlib.h>
#include "./utils/error_codes.h"
#include "./utils/operation_codes.h"
#include "queue.h"

#define MIN_SIZE 16

Queue* queue_create () {
    Queue* queue = malloc(sizeof(Queue));
    queue->data = malloc(sizeof(int) * MIN_SIZE);
    queue->capacity = MIN_SIZE;
    queue->head = 0;
    queue->tail = -1;
    return queue;
}


void queue_double (Queue* queue) {
    int* new_data = malloc(sizeof(int) * queue->capacity * 2);
    if (new_data == NULL) {
        printf("Error resizing the queue from %d to %d capacity\n", queue->capacity, queue->capacity * 2);
        exit(MALLOC_FAILURE);
    }
    for (int i = 0; i < queue->capacity; i++) {
        new_data[i] = queue->data[i];
    }
    queue->data = new_data;
    queue->capacity = queue->capacity * 2;
}

void queue_reduce (Queue* queue) {
    int* new_data = malloc(sizeof(int) * queue->capacity / 2);
    if (new_data == NULL) {
        printf("Error resizing the queue from %d to %d capacity\n", queue->capacity, queue->capacity / 2);
        exit(MALLOC_FAILURE);
    }
    for (int i = queue->head; i < queue->tail; i++) {
        new_data[i - queue->head] = queue->data[i];
    }
    queue->data = new_data;
    queue->tail -= queue->head;
    queue->head = 0;
    queue->capacity = queue->capacity / 2;
}

void queue_push (Queue* queue, int value) {
    if (queue->tail >= queue->capacity - 1) queue_double(queue);
    queue->tail++;
    queue->data[queue->tail] = value;
}

int queue_pop (Queue* queue) {
    if (queue-> tail < 0) {
        printf("OUT_OF_BOUNDS Error on queue_pop\n");
        return OUT_OF_BOUNDS;
    }
    int value = queue->data[queue->head];
    queue->data[queue->head] = 0;
    queue->head++;
    if (queue->capacity > MIN_SIZE && queue->tail - queue->head <= queue->capacity / 4) queue_reduce(queue);
    else if (queue->head >= queue->tail + 1) {
        queue->head = 0;
        queue->tail = -1;
    }
    return value;
}

void queue_print(Queue* queue) {
    printf("Queue {");
    if (queue->tail >= 0) {
        for (int i = queue->head; i < queue->tail; i++) {
            printf("%d, ", queue->data[i]);
        }
        printf("%d", queue->data[queue->tail]);
    }
    printf("} (%d pushed | head: %d | tail: %d)\n", queue->tail - queue->head + 1, queue->head, queue->tail);
}


void test_operation (int operation, int length, int value, int repeat) {
    printf(
        "\nTESTING OPERATION %s -- | value: %d | repeating %d more times\n",
        operation_to_string(operation), value, repeat
    );
    Queue* queue = queue_create();
    for (int i = 0; i < length; i++) {
        queue_push(queue, (i + 1) * 10);
    }
    queue_print(queue);
    switch (operation) {
        case OPERATION_INSERT:
            for (int i = repeat; i >= 0; i--) queue_push(queue, value);
            break;
        case OPERATION_REMOVE: {
            int operation_remove_result;
            for (int i = repeat; i >= 0; i--) operation_remove_result = queue_pop(queue);
            printf("last value popped: %d\n", operation_remove_result);
            break;
        }
    }
    queue_print(queue);
}

void queue_debug_print (Queue* queue) {
    for (int i = 0; i < queue->capacity; i++) {
        printf("%d\n", queue->data[i]);
    }
}


int main () {
    Queue* queue = queue_create();

    for (int i = 0; i < 10; i++) {
        queue_push(queue, (i + 1) * 10);
    }

    // queue_debug_print(queue);
    // printf("pop: %d", queue_pop(queue)); printf("head: %d | tail: %d\n", queue->head, queue->tail);
    // queue_debug_print(queue);
    // printf("pop: %d", queue_pop(queue)); printf("head: %d | tail: %d\n", queue->head, queue->tail);
    // queue_debug_print(queue);

    // test_operation(OPERATION_INSERT, 0, 999, 0);
    // test_operation(OPERATION_INSERT, 15, 999, 0);
    // test_operation(OPERATION_INSERT, 16, 999, 0);
    // test_operation(OPERATION_INSERT, 0, 999, 15);

    test_operation(OPERATION_REMOVE, 1, 0, 0);
    test_operation(OPERATION_REMOVE, 0, 0, 0);
    test_operation(OPERATION_REMOVE, 16, 0, 15);
    test_operation(OPERATION_REMOVE, 32, 0, 15);
    test_operation(OPERATION_REMOVE, 64, 0, 48);
}
