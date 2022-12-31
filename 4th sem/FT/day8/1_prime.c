#include <stdio.h>
#include "1_prime.h"
// if i exists, make a[i] 1 otherwise 0
void fill(int* a, int n)
{
	for(int i = 2; i <= n; ++i)
	{
		a[i] = 1;
	}
}

void disp(int* a, int n)
{
	for(int i = 2; i <= n; ++i)
	{
		if(a[i])
		{
			printf("%d ", i);
		}
	}
}

void filter(int* a, int n)
{
	for(int i = 2; i <= n; ++i) // can we stop the iteration earlier
	{
		if(a[i])
		{
			for(int j = i + i; j <= n; j += i)
			{
				a[j] = 0;
			}
		}
	}
	
}
