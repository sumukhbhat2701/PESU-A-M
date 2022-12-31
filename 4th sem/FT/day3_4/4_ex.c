#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p;
	p = (int *) malloc(5 * sizeof(int));
	p[0] = 10;
	p[4] = 50;
	// what if we free(p + 1); // undefined behaviour
	free(p);
	
	
	int *q;
	q = (int*) malloc(sizeof(int));
	*q = 100;
	free(q);
}
/*
book keeping or house keeping:
On dynamic allocation, size allocated is stored in some location.
This can be accessed given the pointer value.

*/
