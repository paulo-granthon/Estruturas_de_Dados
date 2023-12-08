#define RMIN 1
#define RMAX 100

int* array_create (int size);

int* array_create_desc (int size);

void array_print(int* array, int size);

void array_print_slice(int* array, int start, int end);

int* array_copy(int* array, int size);
