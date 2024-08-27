#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    Person* next;
};

// Function to enqueue a new person to the queue
void enqueue(Person*& head, const std::string& name, int age) {
    Person* newPerson = new Person();
    newPerson->name = name;
    newPerson->age = age;
    newPerson->next = nullptr;

    if (head == nullptr) {
        head = newPerson;
    } else {
        Person* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newPerson;
    }
}

// Function to dequeue a person from the queue
Person* dequeue(Person*& head) {
    if (head == nullptr) {
        return nullptr; // Queue is empty
    }

    Person* removed = head;
    head = head->next;
    return removed;
}

// Function to print all people in the queue
void printPeople(const Person* head) {
    const Person* current = head;
    while (current != nullptr) {
        std::cout << current->name << " is " << current->age << " years old." << std::endl;
        current = current->next;
    }
}

int main() {
    Person* head = nullptr;

    // Enqueue people to the queue
    enqueue(head, "Alice", 25);
    enqueue(head, "Bob", 30);
    enqueue(head, "Charlie", 28);

    // Print the queue
    printPeople(head);

    // Dequeue people from the queue
    Person* removedPerson = dequeue(head);
    if (removedPerson != nullptr) {
        std::cout << removedPerson->name << " was dequeued from the queue." << std::endl;
        delete removedPerson;
    }

    // Print the updated queue
    printPeople(head);

    // Deallocate memory
    while (head != nullptr) {
        Person* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}