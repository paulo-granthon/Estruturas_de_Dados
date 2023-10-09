#include <stdio.h>

static int recursive_max (int v[], int n) {
    if (n == 1) return v[0];
    int x = recursive_max(v, n - 1);
    return x > v[n-1] ? x : v[n-1];
}

int main () {
    printf("max of [1, 2, 3]: {%d}\n", recursive_max((int[]){1, 2, 3}, 3));
    printf("max of [7, 110, 33]: {%d}\n", recursive_max((int[]){7, 110, 33}, 3));
    printf("max of [9, 0, 1]: {%d}\n", recursive_max((int[]){9, 0, 1}, 3));
    printf("max of [1]: {%d}\n", recursive_max((int[]){1}, 1));
    printf("max of [0, 0]: {%d}\n", recursive_max((int[]){0, 0}, 2));
}
