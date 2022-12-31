// pointer to function
#include <stdio.h>

int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }

/*
int x; // variable
typedef int y; // type
y a;
*/
// typedef for pointer to function

typedef int (*ptr_fn_t)(int, int);

int a[10]; // variable
typedef int array_t[10];
array_t b; // b is an array of 10 elements

int main()
{
	int (*ptr_fn)(int, int);
	//ptr_fn = &add;
	ptr_fn = add;
	
	//printf("res : %d\n", (*ptr_fn)(10, 20));
	printf("res : %d\n", ptr_fn(10, 20));
	
	ptr_fn_t p = mul;
	printf("res : %d\n", p(10, 20));
	
	
}
/*
for declarations : K & R

int a; // int
int *p; // pointer to int
int **pp; // pointer to pointer to int
int b[5]; // array of int
int *c[5]; // array of pointers to int
int (*d)[5]; // pointer to an array of int
int e(int); // fn declaration; parameter : int; return : int
int* f(int); // fn declaration; parameter : int; return : int*
int (*g)(); // pointer to a fn ; no parameters; returns an int
int* (*h)(int*); // pointer to a fn; para : int*; return int*
int (*f[4])(); // array of 4 pointers to function returning int 

*/







