
#ifndef PCH_H
#define PCH_H

// The non-standard libraries are include only in some compilers
// can make incompatibilities
#include <conio.h>			// getch() clrscr() gotoxy() textcolor() textbackground()
#include <windows.h>

// STandard Libraries
// 'using namespace SOMETHING' makes reference to another namespace (a custom scope)
// and avoids putting SOMETHING:: every time you use something from inside this namespace
// namespaces are used to avoid name redundancy problems, f.e: a class and a struct of the same name
// 'using namespace std' is useful but is considered a bad practice because it imports all 
// elements inside SOMETHING and could make collision if 2 libs (std & std2) hace the same name functions
// C header files have a .h extension, C++ header files either have .hpp or nothing at all

// STL has 3 main groupings: Containers, Iterators and Algorithms
// Containers has other 2 groups: Sequencial containers and associative containers
// (see stl containers) 


#include <iostream>			// cin cout
#include <fstream>			// For working with files

#include <string>			// C++ philosophy
#include <cstring>			// C philosophy with the character '\n' at the end

#include <vector>
#include <iterator>			// A predefined pointer to iterate over containers
#include <algorithm>		// Search, reverse, replace, remove, sort...

#include <limits>			// To query various properties of arithmetic types
#include <ctime>			// To get and manipulate date and time
#include <numeric>			// Algorithms to work with seq of num values

#include <cstdlib>			// srand(), memory management... #include<stdlib.h> in C

#include <functional>		// For manage functions as modules
#include <memory>			// Dynamic mem. malloc, calloc... unique_ptr

#endif //PCH_H

// PreCompiled Header (PCH)
	// Used to save time in the compile time
	// Don't compile every time you compile
	// Just compile the first time
	// Only headers you will not modify 

// 'include< >' search around all the file system
// 'include" "' search first in the same folder & then all file system
// <> are used for third-party libraries and "" for our own libraries

// <string> VS <cstring> :
	//Flexible storage capacity
	//Constant - time string length retrieval(rather than a linear - time functional check)
	//No need to worry about manual memory management or resizing strings
	//Boundary issues are handled for me, with or without a null character.
	//Intuitive assignment using the = operator rather than strcpy
	//Intuitive comparison using the == operator rather than strcmp
	//Intuitive interfaces for other operations such as concatenation(+operator is nice!), tokenization