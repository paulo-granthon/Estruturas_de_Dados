#ifndef queue_h
#define queue_h

#define DECLARE_QUEUE_TYPE(name, type)            \
    typedef struct name {                         \
        type value;                               \
        struct name* next;                        \
    } name;                            

#define DECLARE_QUEUE_FUNCTIONS(name, type)       \
    name* name##_create(type value);              \
    void name##_push(name* q, type value);        \
    type name##_pop(name* q);

#endif
