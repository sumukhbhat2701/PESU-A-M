#include <stdio.h>

// #define 
//	creates pre-processor variables
//	anywhere in the code
//	redefine a pre-processor variable
//  does not know 'C'
//	no scope

// variables on in a data structure : variable name and value(key value pairs)
// type of pre-processor variable : strings

/*
#define A 20
int main()
{
	printf("A : %d\n", A);
}
*/

/*
int main()
{
	#define A 20
	printf("A : %d\n", A);
}
*/

/*
#define A 10
int main()
{
	#define A 20
	printf("A : %d\n", A);
}
*/
/*
#define A 10
int main()
{
	printf("one : A : %d\n", A);
	{
		#define A 20
		printf("two : A : %d\n", A);
	}
	printf("three : A : %d\n", A);
	
}
// 20 20 20
// 10 20 20  ok
// 10 20 10
*/

//*
#define A B
#define B xyz

int main()
{
	A
	B
}

/// ???
*/
// pre-processor variable:
// a) #define
// b) command line -D
// $ gcc -c -DA=111 1_ex.c 
/*
int main()
{
	printf("A : %d\n", A);
}
*/







