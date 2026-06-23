/*
	This example shows how to statically link a seperate library from within the same solution (19_Engine.proj)

	Essentially almost the same as external static linking to a library:
		This is done via the project properties for Visual Studio Projects (and is MSVC compiler-specific I assume?)
		include files directory: Properties -> C/C++  -> General -> Additional Include Directories

	Except the library files do not need to be set in the linker properties. You and simply right-click the project and click 'Add Reference' and point to the target project.
*/

// include the header file from the target library
#include "engine.h"
#include <iostream>

int main()
{
	// call a function from the library
	engine::print_message();

	std::cin.get();
}