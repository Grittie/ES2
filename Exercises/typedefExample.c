#include <stdio.h>

// Define a new type 'Distance' as an alias for the 'double' data type
typedef double Distance;

typedef struct
{
    char name[25];
    char password[12];
    int id;
} User;

int main() {
    // Declare variables using the new type 'Distance'
    Distance distance1 = 10.5;
    Distance distance2 = 8.2;

    // Perform operations using the 'Distance' type
    Distance totalDistance = distance1 + distance2;

    // Display the result
    printf("Total distance: %.2f\n", totalDistance);

    // Creating a user struct
    User user1 = {"Grit", "password1234", 1};
    
    printf("%s\n", user1.name);
    printf("%s\n", user1.password);
    printf("%d\n", user1.id);

    return 0;
}
