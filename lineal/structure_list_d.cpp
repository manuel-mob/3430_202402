#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    Person* people = nullptr;
    int size = 0;
    int capacity = 10; // Initial capacity

    // Allocate initial memory
    people = new Person[capacity];

    // Add elements
    people[0] = {"Alice", 25};
    people[1] = {"Bob", 30};
    people[2] = {"Charlie", 28};
    size = 3;

    // Check if the list needs to be resized
    if (size == capacity) {
        capacity *= 2; // Double the capacity
        Person* newPeople = new Person[capacity];
        for (int i = 0; i < size; ++i) {
            newPeople[i] = people[i];
        }
        delete[] people;
        people = newPeople;
    }

    // Iterate over the list and print information
    for (int i = 0; i < size; ++i) {
        std::cout << people[i].name << " is " << people[i].age << " years old." << std::endl;
    }

    // Deallocate memory
    delete[] people;

    return 0;
}