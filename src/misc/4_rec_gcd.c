#include <stdio.h>


// returns the greatest common divisor between `a` and `b` -- loop version
static int greatest_common_divisor (int a, int b) {

    // define the bigger and smaller numbers between a and b
    int max = a > b ? a : b;
    int min = b < a ? b : a;

    // loop through numbers between `min` and 2 (inclusive)
    for (int i = min; i >= 2; i--) {

        // modulus operator to check if `i` divides both `min` and `max` without remaining
        // if any fail, this is not the number
        if (max % i != 0) continue;
        if (min % i != 0) continue;

        // `i` divides both numbers without remaining, this is the greatest common divisor
        return i;
    }

    // exited loop without finding a match, the GCD is 1
    return 1;
}


// returns the greatest common divisor between `a` and `b` -- recursive version
static int rec_greatest_common_divisor (int a, int b, int i) {

    // define the bigger and smaller numbers between a and b
    int max = a > b ? a : b;
    int min = b < a ? b : a;

    // if `i` is undefined, set `i` to `min`
    if (i == 0 || i == a || i == b) i = min;

    // reached 1 without finding a match, the GCD is 1
    if (min == 1) return 1;

    // modulus operator to check if `i` divides both `min` and `max` without remaining
    // if any fail, this is not the number
    if (max % i != 0 || min % i != 0) return rec_greatest_common_divisor(min, max, i - 1);

    // `i` divides both numbers without remaining, this is the greatest common divisor
    return i;
}


// lazy run and output for loop version
void test_and_print_gdc (int a, int b) {
    int result = greatest_common_divisor(a, b);
    printf("the greatest common divisor of `%d` and `%d` is `%d`\n", a, b, result);
}


// lazy run and output for recursive version
void rec_test_and_print_gdc (int a, int b) {
    int result = rec_greatest_common_divisor(a, b, 0);
    printf("the greatest common divisor of `%d` and `%d` is `%d`\n", a, b, result);
}


int main () {

    printf("not recursive:\n");
    test_and_print_gdc(15, 5);
    test_and_print_gdc(21, 7);
    test_and_print_gdc(14, 12);
    test_and_print_gdc(16, 6);
    test_and_print_gdc(5, 15);
    test_and_print_gdc(30, 25);
    test_and_print_gdc(25, 100);
    test_and_print_gdc(90, 120);

    printf("\nrecursive:\n");
    rec_test_and_print_gdc(15, 5);
    rec_test_and_print_gdc(21, 7);
    rec_test_and_print_gdc(14, 12);
    rec_test_and_print_gdc(16, 6);
    rec_test_and_print_gdc(5, 15);
    rec_test_and_print_gdc(30, 25);
    rec_test_and_print_gdc(25, 100);
    rec_test_and_print_gdc(90, 120);
}
