#include <iostream>
#include <cmath>

int main()
{
    double x = 3;
    double y = 4;

    double min = std::min(x, y);
    std::cout << min << '\n';

    double max = std::max(x, y);
    std::cout << max << '\n';

    double pow = std::pow(2, 3);
    std::cout << pow << '\n';

    double sqrt = std::sqrt(9);
    std::cout << sqrt << '\n';

    int abs = std::abs(-5);
    std::cout << abs << '\n';

    double r = 3.14;
    int rounded = std::round(r);
    std::cout << rounded << '\n';

    int ceil = std::ceil(r);
    std::cout << ceil << '\n';

    int floor = std::floor(r);
    std::cout << floor << '\n';

    return 0;
}
