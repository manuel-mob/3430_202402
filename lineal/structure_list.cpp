#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    Person* next; // Pointer to the next person in a linked list
};

int main() {
    Person* person1 = new Person();
    person1->name = "Alice";
    person1->age = 25;

    Person* person2 = new Person();
    person2->name = "Bob";
    person2->age = 30;

    // Link the people together
    person1->next = person2;

    // Access the linked list
    Person* current = person1;
    while (current != nullptr) {
        std::cout << current->name << " is " << current->age << " years old." << std::endl;
        current = current->next;
    }

    // Deallocate memory
    delete person1;
    delete person2;

    return 0;
}