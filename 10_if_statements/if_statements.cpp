#include <iostream>

int main()
{
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age >= 100)
    {
        std::cout << "You're too old, get out..";
    }
    else if (age >= 18)
    {
        std::cout << "Welcome to the site!";
    }
    else if (age < 0)
    {
        std::cout << "You haven't been born yet, lol..";
    }
    else
    {
        std::cout << "You're not allowed here, scrub";
    }

    return 0;
}
