#include <stdio.h>
#include <string.h>
#include "./data_structures/linked_list.h"
#include "./data_structures/linked_list_headless.h"
#include "./data_structures/stack.h"
#include "./data_structures/queue.h"

LinkedList* linked_list = NULL;
Headless* headless = NULL;
Stack* stack = NULL;
Queue* queue = NULL;


int proccess_input (char buffer[]) {
    printf("You entered: %s\n", buffer);

    if (strcmp(buffer, "exit\n") == 0) return 1;
    return 0;
}

int main() {

    char buffer[25];

    while (1) {
        printf("Enter something: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (proccess_input(buffer) == 1) break;
    }

    printf("Exiting program\n");
}
