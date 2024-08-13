#include <iostream>
#include <string>
#include <cstdlib>

// Function to check if a number is even or odd
void checkEvenOdd(int number) {
    if (number % 2 == 0) {
        std::cout << number << " is even." << std::endl;
    } else {
        std::cout << number << " is odd." << std::endl;
    }
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    // Access command-line arguments and convert to integer
    int inputNumber = std::atoi(argv[1]);

    // Output the input number from command line
    std::cout << "You provided the number: " << inputNumber << std::endl;

    // Read another number from standard input
    int anotherNumber;
    std::cout << "Enter another number: ";
    std::cin >> anotherNumber;

    // Call the function to check if numbers are even or odd
    checkEvenOdd(inputNumber);
    checkEvenOdd(anotherNumber);

    // Loop through numbers and print if they are even or odd
    for (int i = 1; i <= 10; ++i) {
        checkEvenOdd(i);
    }

    // Example of a basic decision and variable declaration
    int sum = inputNumber + anotherNumber;
    if (sum > 20) {
        std::cout << "The sum of " << inputNumber << " and " << anotherNumber << " is greater than 20." << std::endl;
    } else {
        std::cout << "The sum of " << inputNumber << " and " << anotherNumber << " is not greater than 20." << std::endl;
    }

    return 0;
}

