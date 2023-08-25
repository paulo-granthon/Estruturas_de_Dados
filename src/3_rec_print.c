#include <stdio.h>

static void print_recursive_array (int v[], int n) {
    if (n > 1) print_recursive_array(v, n-1);
    printf("number [%d]: %d\n", n, v[n-1]);
}

static void print_recursive (int n) {
    if (n > 1) print_recursive(n - 1);
    printf("%d\n", n);
}


int main () {
    print_recursive_array((int[]){1, 2, 3}, 3);
    print_recursive_array((int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, 10);
    print_recursive_array((int[]){82639, 20378, 1269, 95871, 2, 192}, 6);

    print_recursive(5);
    print_recursive(11);
    print_recursive(7);
}
