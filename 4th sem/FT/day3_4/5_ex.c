#include <stdio.h>
#include <stdlib.h>

int main()
{
	{
		int *p;
		p = (int *) malloc(5 * sizeof(int));
		p[0] = 10;
		p[4] = 50;
	}
	// no more p
	// location; no access : garbage
	// C : no garbage collector
	// memory leak

}

