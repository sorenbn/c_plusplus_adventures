#include "logger.h"
#include <iostream>

int main() 
{
	const char* message = "Hello, World";
	const int length = 12;

	init_logger();
	log_message(message);

	for (int i = 0; i < length; i++)
	{
		if (i % 2 == 0) 
		{
			const char c = message[i];
			std::cout << c << std::endl;
		}
	}

	return 0;
}