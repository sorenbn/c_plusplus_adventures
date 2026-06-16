#include <iostream>

int main()
{
    int students = 20;

    students++;
    std::cout << students << '\n';

    students += 2;
    std::cout << students << '\n';

    students -= 3;
    std::cout << students << '\n';

    students *= 2;
    std::cout << students << '\n';

    students /= 2;
    std::cout << students << '\n';

    students /= 3;
    std::cout << students << '\n';

    students = 20;
    int remainder = students % 3;
    std::cout << remainder << '\n';

    // order of operation:
    // parenthesis
    // multiplication & division
    // addition & subtraction
    students = 6 - 5 + 4 * 3 / 2;
    std::cout << students << '\n';

    return 0;
}
