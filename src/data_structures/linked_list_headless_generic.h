#ifndef LINKED_LIST_HEADLESS_H
#define LINKED_LIST_HEADLESS_H

#define DECLARE_HEADLESS_TYPE(name, type) \
    typedef struct name { \
        type value; \
        struct name* next; \
    } name

#define DECLARE_HEADLESS_FUNCTIONS(name, type) \
    name* name##_create(type value, name* next); \
    int name##_add(name* h, type value); \
    int name##_insert(name** h, type value, int i); \
    name* name##_find_previous(name* wanted, name* h); \
    int name##_remove(name** h); \
    int name##_remove_at(name* h, int i); \
    int name##_index_of(name* h, type value, int i); \
    int name##_contains(name* h, type value); \
    void name##_print(name* h)

#endif
