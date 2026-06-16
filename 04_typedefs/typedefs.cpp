#include <iostream>
#include <vector>

typedef std::string text_t;
typedef int number_t;
typedef std::vector<std::pair<std::string, int>> pairlist_t;

// 'Using' is a more 'modern' approach (more suitable for templates/generics)
using str = std::string;

int main()
{
    text_t name = "Dumpy";
    number_t age = 34;

    str occupation = "Gamer with big G";

    pairlist_t list;

    std::cout << name << '\n';
    std::cout << age << '\n';
    std::cout << occupation << '\n';

    return 0;
}
