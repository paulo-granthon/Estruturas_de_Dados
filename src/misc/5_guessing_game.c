#include <stdio.h>
#include <stdlib.h>

/*
 * Recursive guessing game loop. Parameters:
 * `ra`: the starting range of the number to be guessed.
 * `rb`: the ending range of the number to be guessed.
 * `n`: the number to be guessed. Call `guess` with any number outside of the range to generate a new random one.
 * `x`: the number of tries left.
*/
static int guess (int ra, int rb, int n, int x) {

    // if no tries left
    if (x == 0) return 1;

    // if n is invalid (undefined), define n
    if (n < ra || n > rb) n = rand() % (rb - ra) + ra;

    // initialize the new guess integer
    int g;

    // prompt user for new input
    printf("%d tries left. Guess a number between %d and %d: ", x, ra, rb);

    // receive the input
    scanf("%d", &g);

    // if guess is correct, interrupt recursion loop
    if (g == n) return 0;

    // guess incorrect, warn the player and return a new try
    printf("Sorry, you guessed incorreclty, try again\n");
    return guess(ra, rb, n, x - 1);
}

/*
 * Recursive guessing game loop with hints (too low, too high). Parameters:
 * `ra`: the starting range of the number to be guessed.
 * `rb`: the ending range of the number to be guessed.
 * `n`: the number to be guessed. Call `guess` with any number outside of the range to generate a new random one.
 * `x`: the number of tries left.
*/
static int guess_hints (int ra, int rb, int n, int x) {
    if (x == 0) return 1;
    if (n < ra || n > rb) n = rand() % (rb - ra) + ra;
    int g;
    // prompt user for new input
    printf("%d tries left. Guess a number between %d and %d: ", x, ra, rb);

    // receive the input
    scanf("%d", &g);

    // if guess is correct, interrupt recursion loop
    if (g == n) return 0;

    // guess incorrect, warn the player and return a new try
    printf("Sorry, you guessed too %s\n", g < n ? "low" : "high");
    printf("g: %d | n: %d\n", g, n);
    return guess(ra, rb, n, x - 1);
}

int main () {

    // define starting range (`ra`), ending range (`rb`), and number  tries (`c`)
    int ra = 0, rb = 10, c = 5;

    int mode;
    printf("Choose the mode you want to play.\n0. Full Blind.\n1. With hints (too Low / too High).");
    scanf("%d", &mode);
    if (mode < 0 || mode > 1) return main();

    // initiate the guessing game. If, at some point, user guesses correclty, print the success message
    if (0 == (mode == 0 ? guess(ra, rb, ra-1, c) : guess_hints(ra, rb, ra-1, c))) printf("\nCongratulations, you guessed the number!\n");

    // user spent all the tries without guessing the correct number
    else printf("\nSorry, you lose the game\n");
}
