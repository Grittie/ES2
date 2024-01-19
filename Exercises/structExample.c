#include <stdio.h>
#include <string.h>

// Define a struct named 'Person' with members for name, age, and salary
struct Person {
    char name[50];
    int age;
    float salary;
};

int main() {
    // Declare a variable of type 'Person'
    struct Person person1;

    // Assign values to the members of the 'person1' struct
    strcpy(person1.name, "John Doe");
    person1.age = 25;
    person1.salary = 50000.50;

    // Display the information stored in the struct
    printf("Person Information:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Salary: %.2f\n", person1.salary);

    return 0;
}
