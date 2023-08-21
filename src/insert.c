#import <stdio.h>

// define the array capaciry
#define NUMBERS_LEN 50

// define the current tail of the array 
static int CUR_TAIL = NUMBERS_LEN / 2;


// inserts into the array 
static int insert_ordered(int number, int numbers[], int tail) {

    // loop through numbers up to the current tail of the array
    for (int i = tail - 2; i >= 0; i--) {
        if (number < numbers[i]) {
            numbers[i + 1] = numbers[i];
            continue;
        }
        numbers[i + 1] = number;
        return 0;
        CUR_TAIL++;
    }
    return 1;
}


static void init_array(int numbers[], int tail) {

    // loop through array
    for (int i = 0; i < tail; i ++) {

        // populate with multiples of 2
        numbers[i] = i * 2;
    }
}

int main () {

    // initialize array
    int numbers[NUMBERS_LEN] = {0};

    // initialize the array with values
    init_array(numbers, CUR_TAIL);

    printf("\nINITIAL LIST:\n\n");
    for (int i = 0; i < NUMBERS_LEN; i++) {
        printf("{%d}\n", numbers[i]);
    }

    // execute insert
    insert_ordered(13, numbers, CUR_TAIL);

    // print updated array
    printf("\nFINAL LIST:\n\n");
    for (int i = 0; i < NUMBERS_LEN; i ++) {
        printf("{%d}\n", numbers[i]);
    }

    return 0;
}

