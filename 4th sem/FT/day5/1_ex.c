#include <stdio.h>
#if 0
// version 1
void what(int x, int y)
{
	int temp = x; x = y; y = temp;
}

int main()
{
	int a = 10; int b = 20;
	what(a, b);
	printf("a : %d b : %d\n", a, b);
}
#endif
#if 0
// version 2
void what(int *x, int *y)
{
	int *temp = x; x = y; y = temp;
}

int main()
{
	int a = 10; int b = 20;
	what(&a, &b);
	printf("a : %d b : %d\n", a, b);
}
#endif
#if 0
// version 3
void what(int **x, int **y)
{
	int **temp = x; x = y; y = temp;
}

int main()
{
	int a = 10; int b = 20;
	int *p = &a; int *q = &b;
	what(&p, &q);
	printf("a : %d b : %d\n", a, b);
}
#endif
#if 0
// version 4
void what(int **x, int **y)
{
	int *temp = *x; *x = *y; *y = temp;
}

int main()
{
	int a = 10; int b = 20;
	int *p = &a; int *q = &b;
	what(&p, &q);
	printf("a : %d b : %d\n", a, b);
	printf("a : %d b : %d\n", *p, *q);
}
#endif

#if 0
// version 5
void what(int **x, int **y)
{
	int temp = **x; **x = **y; **y = temp;
}

int main()
{
	int a = 10; int b = 20;
	int *p = &a; int *q = &b;
	what(&p, &q);
	printf("a : %d b : %d\n", a, b);
}
#endif
// version 6
void what(int *x, int *y)
{
	int temp = *x; *x = *y; *y = temp;
}

int main()
{
	int a = 10; int b = 20;
	int *p = &a; int *q = &b;
	what(p, q);
	printf("a : %d b : %d\n", a, b);
}



