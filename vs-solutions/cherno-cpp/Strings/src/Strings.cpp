#include <iostream>
#include <string>

void c_style_string() 
{
    // C-style string, basically a pointer to a character array
    const char* name = "Dumpy";
    std::cout << name << "\n";

    // every string has a '\0' appended at the end, to know when the string has ended.
    // if it wasn't there, cout wouldn't know when to stop reading the memory of the string.
    char name2[6] = { 'D', 'u', 'm', 'p', 'y', '\0' };
    std::cout << name2 << "\n";
}

void cpp_string()
{
    std::string name = "Dumpy";
    std::cout << name << "\n";

    std::cout << name.size() << "\n";

    // append
    name += " Dumpyson";
    std::cout << name << "\n";

    // append via string constructor
    std::string full_name = std::string("Dumpy") + " " + "Dumpyson";
    std::cout << full_name << "\n";

    // std::string.find returns the position of character you're looking for
    // npos = illegal character, meaning it didn't find it.
    bool contains = full_name.find("um") != std::string::npos;
}

// make sure to pass the string as a const reference, otherwise a copy will be made (unless you actually need a copy, ofc)
void print_string(const std::string& string)
{
    std::cout << string << std::endl;
}

void string_literals() 
{
    // a string literal
    // 5 characters but represented as a const char[6] array to have room for the null termination character '\0'
    "Dumpy";

    // null terminating character in the middle of the string
    // will only print 2 since it counts until the first \0
    const char name[7] = "Du\0mpy";
    std::cout << strlen(name) << std::endl;

    // char* is the same as char[]
    // char is a 1-byte per character
    const char* name2 = "Du\0mpy";

    // wide characters
    const wchar_t* wide_string = L"Dumpy";

    // 2-byte per character (UTF-16)
    const char16_t* char_16_string = u"Dumpy";
    // 4-byte per character (UTF-32)
    const char32_t* char_32_string = U"Dumpy";

    // multi-line string (R stands for 'raw')
    const char* example = R"(Line1
Line2
Line3
Line4)";

    std::cout << example << std::endl;

    // another way to multi-line
    const char* example2 = "Line1"
        "Line2\n"
        "Line3"
        "Line4";

    std::cout << example2 << std::endl;
}

int main()
{
    c_style_string();
    cpp_string();

    std::string name = "Dumpy";
    print_string(name);

    string_literals();
}