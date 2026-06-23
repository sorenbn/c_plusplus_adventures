#include <iostream>

// macros
#define LOG(x) std::cout << x << std::endl

// forward declerations
void const_pointers();
void references();
void increment_by_pointer(int* number);
void increment_by_reference(int& number);

int main()
{
    const_pointers();
    references();

    std::cin.get();
    return 0;
}

void const_pointers()
{
    LOG("######## POINTERS ########");

    // variable
    int number = 8;
    LOG(number);

    // pointer
    int* number_pointer = &number;
    // de-reference the pointer and set the value at that address
    *number_pointer = 40;

    LOG(number);

    // address of number
    increment_by_pointer(&number);
    LOG(number);
    // directly pass the number pointer we created
    increment_by_pointer(number_pointer);
    LOG(number);

    // allocate a char* buffer on the heap (char = 1 byte, total = 8 bytes)
    char* buffer = new char[8];
    // initialize all memory to 0
    memset(buffer, 0, 8);

    // pointer to a pointer
    char** buffer_pointer = &buffer;

    // delete the memory again (using the delete[] array keyword)
    delete[] buffer;
}

void references()
{
    LOG("######## REFERENCES ########");
    // variable
    int number = 5;
    LOG(number);
 
    // reference
    int& number_reference = number;
    number_reference = 2;
    LOG(number);

    increment_by_reference(number_reference);
    LOG(number);

    int number2 = 8;
    // small gotcha, copies the value of number2 into the reference of number
    // not possible to point to a new reference/value
    number_reference = number2;
    LOG(number);
}

void increment_by_pointer(int* number)
{
    // derefence first, and then increment
    (*number)++;
}

void increment_by_reference(int& number) 
{
    number++;
}