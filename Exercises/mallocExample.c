#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray;
    int size = 5;

    // Dynamic memory allocation using malloc
    dynamicArray = (int *)malloc(size * sizeof(int));

    if (dynamicArray == NULL) {
        // Check if allocation was successful
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }

    // Initialize the dynamic array
    for (int i = 0; i < size; ++i) {
        dynamicArray[i] = i * 2;
    }

    // Display the contents of the dynamic array
    printf("Dynamic Array Contents: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Dynamic memory deallocation using free
    free(dynamicArray);

    // After deallocation, attempting to access the memory could lead to undefined behavior
    // dynamicArray[0] = 42; // Uncommenting this line would lead to undefined behavior

    return 0;
}
