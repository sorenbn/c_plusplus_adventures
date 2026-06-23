#include <iostream>

// only visible inside this file (file scoped, in a way?)
// if we remove static, the linker will clash with the 'some_int' inside main.cpp
static int some_int = 20;

// visible across all files, meaning linker can have issues if the same variable with the same name is defined multiple places
int external_variable = 5;

void external_function()
{
	std::cout << "external function" << std::endl;
}