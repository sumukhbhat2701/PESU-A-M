#include <stdio.h>
#include "1_prime.h"

int main()
{
	int n;
	n = 100;
	unsigned int a[n + 1];
	fill(a, n);
	disp(a, n);
	filter(a, n);
	disp(a, n);
	
}
