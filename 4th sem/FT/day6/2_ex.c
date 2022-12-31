#include <stdio.h>
#include "foo.h"
// function name hijacking
//	changing the program; replace one fn call by another; not modifying the file
// gcc -E -Dfoo=bar  2_ex.c


// build:
//$ gcc -c bar.c
//$ gcc -c -Dfoo=bar  2_ex.c
//$ gcc bar.o 2_ex.o
//$ ./a.out
/*
one
this is bar
two
*/

int main()
{
	printf("one\n");
	foo();
	printf("two\n");
}
