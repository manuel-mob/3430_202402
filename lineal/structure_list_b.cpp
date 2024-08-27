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
    char choice;

    while (true) {
        std::cout << "Choose an action:\n";
        std::cout << "1. Add a person\n";
        std::cout << "2. Remove a person\n";
        std::cout << "3. Print the list\n";
        std::cout << "4. Quit\n";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::string name;
                int age;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter age: ";
                std::cin >> age;
                addPerson(head, name, age);
                break;
            }
            case '2': {
                std::string name;
                std::cout << "Enter name to remove: ";
                std::cin >> name;
                removePerson(head, name);
                break;
            }
            case '3': {
                printPeople(head);
                break;
            }
            case '4': {
                // Deallocate memory and exit
                while (head != nullptr) {
                    Person* temp = head;
                    head = head->next;
                    delete temp;
                }
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}