#include <stdio.h>

int main()
{
	int *p; // uninitialized ; p will have junk value
	// dangling pointer : no location; access
	// dereferencing a dangling pointer : undefined behaviour
	// *p = 111;
	
	int a[] = {11, 22, 33, 44, 55};
	int i = 5;
	// a[i] = 222; // dangling pointer ; undefined behaviour
	//a[100] = 333;
	
}
