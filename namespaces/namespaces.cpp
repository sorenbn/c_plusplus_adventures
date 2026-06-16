namespace first
{
    int x = 1;
}

namespace second
{
    int x = 2;
}

namespace third
{
    int y = 3;
}

#include <iostream>

// use the whole namespace
using namespace third;

// use specific features from namespaces
using std::cout;
using std::endl;

int main()
{
    int x = 0;

    cout << x << endl;
    cout << first::x << endl;
    cout << second::x << endl;

    // 'uses' third namespace implicitly
    cout << y << endl;

    return 0;
}
