#include <stdio.h>

static void print_recursive_array (int v[], int n) {
    if (n > 1) print_recursive_array(v, n-1);
    printf("number [%d]: %d\n", n, v[n-1]);
}

static void print_recursive (int n) {
    if (n > 1) print_recursive(n - 1);
    printf("%d\n", n);
}

static void print_and_run_array (int v[], int n) {
    printf("testing recursive print for array [");
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d]\n", v[n - 1]);
    print_recursive_array(v, n);
} 

static void print_and_run_integer (int n) {
    printf("testing recursive print for integer %d\n", n);
    print_recursive(n);
} 

int main () {
    print_and_run_array((int[]){1, 2, 3}, 3);
    print_and_run_array((int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, 10);
    print_and_run_array((int[]){82639, 20378, 1269, 95871, 2, 192}, 6);

    print_and_run_integer(5);
    print_and_run_integer(11);
    print_and_run_integer(7);
}
