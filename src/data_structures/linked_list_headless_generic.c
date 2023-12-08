#include <stdio.h>
#include <stdlib.h>
#include "../utils/error_codes.h"
#include "../utils/operation_codes.h"
#include "linked_list_headless_generic.h"

#define IMPLEMENT_HEADLESS_FUNCTIONS(name, type)                              \
    name* name##_create(type value, name* next) {                             \
        name* h = malloc(sizeof(name));                                       \
        if (h == NULL) {                                                      \
            perror("Failed to allocate memory for a new " #name);             \
            exit(MALLOC_FAILURE);                                             \
        }                                                                     \
        h->value = value;                                                     \
        h->next = next;                                                       \
        return h;                                                             \
    }                                                                         \
                                                                              \
    int name##_add(name* h, type value) {                                     \
        if (h->next != NULL) return name##_add(h->next, value);               \
        h->next = name##_create(value, NULL);                                 \
        return OK;                                                            \
    }                                                                         \
                                                                              \
    int name##_insert(name** h, type value, int i) {                          \
        if (i > 0) return (*h)->next != NULL ?                                \
            name##_insert(&((*h)->next), value, i - 1)                        \
            : i == 1 ? name##_add(*h, value) : OUT_OF_BOUNDS;                 \
        name* new_h = name##_create(value, *h);                               \
        *h = new_h;                                                           \
        return OK;                                                            \
    }                                                                         \
                                                                              \
    name* name##_find_previous(name* wanted, name* h) {                       \
        return h->next == wanted ? h : name##_find_previous(h->next, wanted); \
    }                                                                         \
                                                                              \
    int name##_remove(name** h) {                                             \
        if (h == NULL || *h == NULL) return OUT_OF_BOUNDS;                    \
        name* new_h = (*h)->next;                                             \
        free(*h);                                                             \
        *h = new_h;                                                           \
        return OK;                                                            \
    }                                                                         \
                                                                              \
    int name##_remove_at(name** h, int i) {                                   \
        if (i > 0)                                                            \
            return (*h)->next == NULL ? OUT_OF_BOUNDS                         \
                : name##_remove_at(&(*h)->next, i - 1);                       \
        return name##_remove(h);                                              \
    }                                                                         \
                                                                              \
    int name##_index_of(name* h, type value, int i) {                         \
        return h->value == value ? i                                          \
            : h->next == NULL ? OUT_OF_BOUNDS                                 \
                : name##_index_of(h->next, value, i + 1);                     \
    }                                                                         \
                                                                              \
    int name##_contains(name* h, type value) {                                \
        return name##_index_of(h, value, 0) == OUT_OF_BOUNDS ? 0 : 1;         \
    }                                                                         \

#define IMPLEMENT_HEADLESS_PRINT(name, type)                                  \
    void name##_print(name* h) {                                              \
        printf("%" #type "%s", h->value, h->next == NULL ? "}\n" : ", ");     \
        if (h->next != NULL) name##_print(h->next);                           \
    }
