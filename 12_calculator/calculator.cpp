#include <iostream>

int main(int argc, char const *argv[])
{
    char operation;
    double num1;
    double num2;
    double result;

    std::cout << "************* CALCULATOR ************* \n";
    std::cout << "Enter either (+ - * /): ";
    std::cin >> operation;

    std::cout << "Enter #1: ";
    std::cin >> num1;

    std::cout << "Enter #2: ";
    std::cin >> num2;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;

    default:
        std::cout << "Not a valid operator!";
        return 1;
    }

    std::cout << "Result: " << result << std::endl;
    std::cout << "************************************** \n";
}
