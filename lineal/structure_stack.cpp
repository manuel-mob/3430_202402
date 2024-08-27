#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    Person* next;
};

// Function to push a new person onto the stack
void push(Person*& head, const std::string& name, int age) {
    Person* newPerson = new Person();
    newPerson->name = name;
    newPerson->age = age;
    newPerson->next = head;
    head = newPerson;
}

// Function to pop a person from the stack
Person* pop(Person*& head) {
    if (head == nullptr) {
        return nullptr; // Stack is empty
    }

    Person* top = head;
    head = head->next;
    return top;
}

// Function to print all people in the stack
void printPeople(const Person* head) {
    const Person* current = head;
    while (current != nullptr) {
        std::cout << current->name << " is " << current->age << " years old." << std::endl;
        current = current->next;
    }
}

int main() {
    Person* head = nullptr;

    // Push people onto the stack
    push(head, "Alice", 25);
    push(head, "Bob", 30);
    push(head, "Charlie", 28);

    // Print the stack
    printPeople(head);

    // Pop people from the stack
    Person* poppedPerson = pop(head);
    if (poppedPerson != nullptr) {
        std::cout << poppedPerson->name << " was popped from the stack." << std::endl;
        delete poppedPerson;
    }

    // Print the updated stack
    printPeople(head);

    // Deallocate memory
    while (head != nullptr) {
        Person* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}