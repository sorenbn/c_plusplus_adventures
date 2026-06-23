#include <iostream>

// if the headers are included in the project itself, use double quotes "lib.h", otherwise use angled brackets <lib.h>
// angled brackets means it's external
#include "GLFW/glfw3.h"
//#include <GLFW/glfw3.h>

/*
	Static library linking:
		The library gets 'embedded' into the executable itself (usually the way to go, if possible)
	Dynamic library linking:
		The library gets linked to your executable at runtime (requires the .dll file to physically be on the target machine running your executable, either next to it or somewhere on the machine itself)

	2 components required for setting up external library:
		Include files, which is typically header files with all the symbols/variables & functions declarations
		Library files, for the linker to know where to find all the symbol/variable & function definitions
*/

int main()
{
	int result = glfwInit();
	std::cout << result << std::endl;
}