#include <iostream>
#include <vector>

struct Person {
    std::string name;
    int age;
};

// Function to find the oldest person
Person findOldestPerson(const std::vector<Person>& people) {
    if (people.empty()) {
        // Handle empty array case
        throw std::runtime_error("Array is empty.");
    }

    Person oldest = people[0];
    for (const Person& person : people) {
        if (person.age > oldest.age) {
            oldest = person;
        }
    }
    return oldest;
}

int main() {
    std::vector<Person> people = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 28}
    };

    Person oldestPerson = findOldestPerson(people);
    std::cout << "The oldest person is: " << oldestPerson.name << std::endl;

    return 0;
}