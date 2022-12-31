#include <stdio.h>
#include "1_server.h"

int main()
{
	printf("ondu\n");
	foo();
	printf("eradu\n");
}

// different steps in executing a program
// 1. edit the program
//		source file
// 2. pre-processing
//		translation or translation unit
//		gcc -E <filename>
// 3. compile
//		object file
//		gcc -c <filename>
// 4. link
//		loadable image
// 5. load
//		process
// 6. run
//		output ...



