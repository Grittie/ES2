#include <stdio.h>

int main() {
    int number = 42;
    int *pointer_to_number;  // Declare a pointer to an integer

    // Assign the address of the 'number' variable to the pointer
    pointer_to_number = &number;

    // Accessing the value indirectly through the pointer
    printf("Value of number: %d\n", *pointer_to_number);

    // Modifying the value indirectly through the pointer
    *pointer_to_number = 100;

    // Now, the original variable 'number' has been changed through the pointer
    printf("Updated value of number: %d\n", number);

    return 0;
}