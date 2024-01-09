#include <stdio.h>
#include "get_next_line.h"

void displayCallCount() {
    // Static variable to keep track of the number of function calls
    static int callCount = 0;

    // Increment the static variable on each function call
    callCount++;

    // Display the current call count
    printf("Function called %d times.\n", callCount);
}

int main() {
    // Calling the function multiple times
    displayCallCount();
    displayCallCount();
    displayCallCount();

    return 0;
}

