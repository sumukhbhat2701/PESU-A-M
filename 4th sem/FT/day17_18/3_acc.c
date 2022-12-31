#include <stdio.h>
int acc1(int a[], int n)
{
	int init = 0;
	for(int i = 0; i < n; ++i)
	{
		init += a[i];
	}
	return init;
}

// flexibility on init value?
int acc2(int a[], int n, int init)
{
	for(int i = 0; i < n; ++i)
	{
		init += a[i];
	}
	return init;
}

int acc3(int a[], int n, int init, int (*op)(int, int))
{
	for(int i = 0; i < n; ++i)
	{
		init = op(init, a[i]);
	}
	return init;
}
int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }

int main()
{
	int a[] = {4, 2, 5, 1, 3};
	// add all the numbers
	printf("res : %d\n", acc1(a, 5));
	printf("res : %d\n", acc2(a, 5, 0));
	printf("res : %d\n", acc2(a, 5, 100));

	printf("res : %d\n", acc3(a, 5, 0, add));
	printf("res : %d\n", acc3(a, 5, 1, mul));

}
