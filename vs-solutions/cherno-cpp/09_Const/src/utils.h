#pragma once

#include <iostream>

void assert(bool statement, const char* message)
{
	if (statement)
		return;

	std::cout << "Assertion failed: " << message << std::endl;
	std::exit(1);
}