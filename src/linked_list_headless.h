typedef struct Headless {
    struct Headless* next;
    int value;
} Headless;

Headless* headless_create(int value, Headless* next);

int headless_add (Headless* h, int value);
int headless_insert (Headless** h, int value, int i);

Headless* headless_find_previous(Headless* wanted, Headless* h);

int headless_remove (Headless** h, int i);

int headless_index_of (Headless* h, int value, int i);
int headless_contains (Headless* h, int value);

void headless_print (Headless* h);
