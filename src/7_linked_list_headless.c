#include <stdio.h>
#include <stdlib.h>
#include "./utils/error_codes.h"
#include "./utils/operation_codes.h"


typedef struct Headless {
    struct Headless* next;
    int value;
} Headless;


Headless* new_headless(int v) {
    Headless* h = malloc(sizeof(Headless));
    if (h == NULL) {
        perror("Failed to allocate memory for a new Headless");
        exit(1);
    }
    return h;
}

void headless_add (Headless* h, int v) {
    if (h->next != NULL) return headless_add(h->next, v);
    h->next = new_headless(v);
}

int headless_insert (Headless* h, int v, int i) {
    if (i != 0) return h->next == NULL ? 1
        : headless_insert(h->next, v, i - 1);
    Headless* new_h = new_headless(v);
    new_h->next = h->next;
    h->next = new_h;
    return 0;
}

// print
// remove
// contains
// index_of

int main () {

    return 0;
}
