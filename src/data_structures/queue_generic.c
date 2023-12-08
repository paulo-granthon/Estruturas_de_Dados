#include <stdio.h>
#include <stdlib.h>
#include "../utils/error_codes.h"
#include "queue_generic.h"

#define IMPLEMENT_QUEUE_FUNCTIONS(name, type)                  \
name* name##_create(type value) {                              \
    name* queue = malloc(sizeof(name));                        \
    if (queue == NULL) {                                       \
        perror("Failed to allocate memory for a new " #name);  \
        exit(MALLOC_FAILURE);                                  \
    }                                                          \
    queue->value = value;                                      \
    queue->next = NULL;                                        \
    return queue;                                              \
}                                                              \
                                                               \
void name##_push (name** head, name** tail, type value) {      \
    if (*head == NULL) {                                       \
        *head = *tail = name##_create(value);                  \
        return;                                                \
    }                                                          \
    (*tail)->next = name##_create(value);                      \
    *tail = (*tail)->next;                                     \
}                                                              \
                                                               \
type name##_pop (name** head, name** tail) {                   \
    type value = (*head)->value;                               \
    *head = (*head)->next;                                     \
    if (head == NULL) *tail = NULL;                            \
    return value;                                              \
}                                                              \
                                                               \
int name##_remove(name** queue) {                              \
    if (queue == NULL || *queue == NULL) return OUT_OF_BOUNDS; \
    name* new_queue = (*queue)->next;                          \
    free(*queue);                                              \
    *queue = new_queue;                                        \
    return OK;                                                 \
}                                                              \
