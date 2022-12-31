#include <stdio.h>
#include "1_prime.h"
#define SIZE (sizeof(int)*8)
// if i exists, make a[i] 1 otherwise 0
void fill(unsigned int* a, int n)
{
	int m = (n / SIZE) + 1;
	for(int i = 0; i <= m; ++i)
	{
		a[i] = ~0;
	}
}

void disp(unsigned int* a, int n)
{
	int base;
	int offset;
	for(int i = 2; i <= n; ++i)
	{
		base = i / SIZE;
		offset = i % SIZE; 
//		if(a[i])
		if(a[base] & (1 << offset))
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

void filter(unsigned int* a, int n)
{
	int base;
	int offset;
	for(int i = 2; i <= n; ++i) // can we stop the iteration earlier
	{
		if(a[i])
		{
			for(int j = i + i; j <= n; j += i)
			{
				base = j / SIZE;
				offset = j % SIZE;
				a[base] &= ~(1 << offset);
			}
		}
	}
	
}
