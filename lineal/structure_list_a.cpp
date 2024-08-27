#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    Person* next;
};

// Function to add a new person to the list
void addPerson(Person*& head, const std::string& name, int age) {
    Person* newPerson = new Person();
    newPerson->name = name;
    newPerson->age = age;
    newPerson->next = head;
    head = newPerson;
}

// Function to remove a person from the list by name
void removePerson(Person*& head, const std::string& name) {
    Person* current = head;
    Person* previous = nullptr;

    while (current != nullptr && current->name != name) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
    }
}

// Function to print all people in the list
void printPeople(const Person* head) {
    const Person* current = head;
    while (current != nullptr) {
        std::cout << current->name << " is " << current->age << " years old." << std::endl;
        current = current->next;
    }
}

int main() {
    Person* head = nullptr;

    // Add people to the list
    addPerson(head, "Alice", 25);
    addPerson(head, "Bob", 30);
    addPerson(head, "Charlie", 28);

    // Print the list
    printPeople(head);

    // Remove a person
    removePerson(head, "Bob");

    // Print the updated list
    printPeople(head);

    // Deallocate memory
    while (head != nullptr) {
        Person* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}