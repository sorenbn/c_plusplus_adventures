#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
    LOG("Hello World!\n");
    
    int number = 8;
    LOG(number);

    int* number_pointer = &number;
    *number_pointer = 40;
    
    LOG(number);

    // allocate a char* buffer on the heap (char = 1 byte, total = 8 bytes)
    char* buffer = new char[8];
    // initialize all memory to 0
    memset(buffer, 0, 8);

    // pointer to a pointer
    char** buffer_pointer = &buffer;

    // delete the memory again
    delete[] buffer;
    std::cin.get();
    return 0;
}