#include <iostream>

int main()
{
    double x = (int)3.14;
    std::cout << x << '\n';

    // getting cast to the ASCII value of '100' = 'd'
    char c = 100;
    std::cout << c << '\n';

    int correct = 8;
    int total_questions = 10;

    double correct_percent = (correct / (double)total_questions) * 100;
    std::cout << correct_percent << "%" << '\n';

    return 0;
}
