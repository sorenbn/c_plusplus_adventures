/*
	Dynamic library linking:
		The library gets linked to your executable at runtime (requires the .dll file to physically be on the target machine running your executable, either next to it or somewhere on the machine itself)
	
	2 components required for setting up external library:
		Include files, which is typically header files with all the symbols/variables & functions declarations
		Library files, for the linker to know where to find all the symbol/variable & function definitions

	This is done via the project properties for Visual Studio Projects (and is MSVC compiler-specific I assume?)
		include files directory: Properties -> C/C++  -> General -> Additional Include Directories
		library files directory: Properties -> Linker -> General -> Additional Library Directories
		library files		   : Properties -> Linker -> Input   -> Additional Dependencies

	Important thing to note about dynamically linked libraries:
		The .dll must be next to the executable file, so copy/paste the glfw3.dll file into the build directory.
		The input section for the linker must link to the 'glfw3dll.lib' file, instead of the 'glfw3.lib' file.
*/

#include <iostream>
#include "GLFW/glfw3.h"

int main()
{
	int result = glfwInit();
	std::cout << result << std::endl;

	std::cin.get();
}