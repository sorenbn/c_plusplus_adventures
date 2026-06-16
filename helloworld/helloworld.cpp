#include <iostream>

int main()
{
    // this is a comment
    std::cout << "Hello World" << '\n';
    std::cout << "How are you?" << '\n';

    // int
    int x;
    x = 5;

    int y = 6;
    int sum = x + y;

    std::cout << sum << std::endl;

    // double
    double price = 13.99;
    std::cout << price << std::endl;

    // char
    char grade = 'A';
    char currency = '$';

    std::cout << grade << std::endl;

    // bool
    bool is_student = true;
    bool powered = false;

    std::cout << is_student << std::endl;

    // string
    std::string name = "Dumpy";
    std::string day_of_week = "Friday";

    std::cout << name << ", is it " << day_of_week << " today?" << std::endl;

    return 0;
}