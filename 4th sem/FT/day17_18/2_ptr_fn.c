#include <stdio.h>

int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }

// callback 
int what(int x, int y, int (*op)(int, int))
{
	return op(x, y);
}

int main()
{
	printf("res : %d\n", what(10, 20, add));
	printf("res : %d\n", what(10, 20, mul));

}
