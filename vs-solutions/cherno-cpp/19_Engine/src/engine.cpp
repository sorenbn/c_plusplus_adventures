#include <iostream>
#include "engine.h"

/*
	This example shows how to statically link a seperate library from within the same solution (19_Game.proj)

	This is the library project, and project must be set as a static library type:
		Properties -> C/C++  -> General -> Configuration Type -> Static Library (.lib)
*/

namespace engine
{
	void print_message()
	{
		std::cout << "Hello from engine!" << std::endl;
	}
}