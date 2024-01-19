#include <stdio.h>

// Define a macro for the constant PI
#define PI 3.14159

// Define a macro for calculating the square of a number
#define SQUARE(x) ((x) * (x))

int main() {
    // Using the PI macro
    double circleArea = PI * 2.0 * 2.0;
    printf("Area of a circle with radius 2: %.2f\n", circleArea);

    // Using the SQUARE macro
    int num = 5;
    int squareResult = SQUARE(num);
    printf("Square of %d: %d\n", num, squareResult);

    return 0;
}
