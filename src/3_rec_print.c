#include <stdio.h>

static void print_recursive (int v[], int n) {
    if (n > 1) print_recursive(v, n-1);
    printf("number [%d]: %d\n", n, v[n-1]);
}


int main () {
    print_recursive((int[]){1, 2, 3}, 3);
    print_recursive((int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, 10);
    print_recursive((int[]){82639, 20378, 1269, 95871, 2, 192}, 6);
}
