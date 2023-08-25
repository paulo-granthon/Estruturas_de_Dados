#include <stdio.h>
#include <stdlib.h>

//  number | tries | guess
static int guess (int ra, int rb, int n, int x, int g) {

    // if no tries left
    if (x == 0) return 1;

    // if n is invalid (undefined), define n
    if (n < ra || n > rb) n = rand() % (rb - ra) + ra;
    int new_g;
    printf("%d tries left. Guess a number between %d and %d: ", x, ra, rb);
    scanf("%d", &new_g);
    if (g != n) return guess(ra, rb, n, x - 1, new_g);
    return 0;
}


int main () {
    
    int ra = 0, rb = 10, c = 10;

    if (guess(ra, rb, ra-1, c, ra-1) == 0) printf("\nCongratulations, you guessed the number!\n");
    else printf("\nSorry, you lose the game\n");



}
