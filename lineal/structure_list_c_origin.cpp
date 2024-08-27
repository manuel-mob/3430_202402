#include <iostream>
#include <list>
#include <string>

struct Person {
    std::string name;
    int age;
    Person* origin;
};

//Funcion para relacionar persona con origen de la enfermedad (otra persona)
void addOrigin(){

}

int main() {
    std::list<Person> people;

    // Add elements to the list
    people.push_back({"Alice", 25});
    people.push_back({"Bob", 30});
    people.push_back({"Charlie", 28});

    // Iterate over the list and print information
    for (const Person& person : people) {
        std::cout << person.name << " is " << person.age << " years old." << std::endl;
        if ( person.origin != nullptr ) {
            std::cout << " The origin is " << person.origin << std::endl;
        }
    }

    return 0;
}