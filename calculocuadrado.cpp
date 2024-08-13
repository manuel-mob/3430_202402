#include <iostream>

double square(double x) // square a double precision floating-point number
{
return x*x;
}

void print_square(double x)
{
    std::cout << "The square of " << x << " is " << square(x) << '\n';
}

int main()
{
    print_square(1.2345); // Print 
    print_square(5.555); // print
}
