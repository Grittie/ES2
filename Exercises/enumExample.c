#include <stdio.h>

// Define an enumeration named Color
typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

void printColor(Color c) {
    switch (c) {
        case RED:
            printf("The color is RED\n");
            break;
        case GREEN:
            printf("The color is GREEN\n");
            break;
        case BLUE:
            printf("The color is BLUE\n");
            break;
        default:
            printf("Unknown color\n");
    }
}

void app_main() {
    // Declare a variable of type Color
    Color myColor = GREEN;

    // Print the current color
    printColor(myColor);
}
