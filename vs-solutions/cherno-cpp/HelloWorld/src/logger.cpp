#include <iostream>
#include "logger.h"

void init_logger() 
{
	std::cout << "Logger initialized!" << std::endl;
}

void log_message(const char* message)
{
	std::cout << message << std::endl;
}