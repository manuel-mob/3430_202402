#include <iostream>

// Define a structure named "Person"
struct Person {
    std::string name;
    int age;
    double height;
};

int main() {
    // Create an array of 3 Person objects
    Person people[3];

    // Initialize the array elements
    people[0].name = "Alice";
    people[0].age = 25;
    people[0].height = 1.70;

    people[1].name = "Bob";
    people[1].age = 30;
    people[1].height = 1.85;

    people[2].name = "Charlie";
    people[2].age = 28;
    people[2].height = 1.75;

    // Access and print information from the array
    for (int i = 0; i < 3; ++i) {
        std::cout << "Name: " << people[i].name << std::endl;
        std::cout << "Age: " << people[i].age << std::endl;
        std::cout << "Height: " << people[i].height << std::endl;
        std::cout << std::endl;
    }

    return 0;
}