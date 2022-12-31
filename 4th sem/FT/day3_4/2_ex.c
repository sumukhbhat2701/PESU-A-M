#include <stdio.h>

void what(int *p, int *q)
{
	int m = *p; int n = *q;
	while(m != n)
	{
		if(m > n)
		{
			m -= n;
		}
		else
		{
			n -= m;
		}
	}
	*p /= m; *q /= n;
}

int main()
{
	int a = 15; int b = 25;
	what(&a, &b); printf("a : %d b : %d\n", a, b);
	what(&a, &a); printf("a : %d\n", a);
}


