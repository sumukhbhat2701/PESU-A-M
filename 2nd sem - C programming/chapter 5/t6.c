#include <stdio.h>

//#define x 25
#ifndef x
 #define x 5
#endif

int main()
{
 #if x == 20
    printf("The value of x is %d",x);
 #elif x > 20	
    printf("The value of x %d is greater than 20 ",x);
 #else 
	printf("The value of x %d is less than 20",x); 
 #endif
 return 0;
}
/*
int main()
{
    printf("The value of x is %d",x);
    return 0;
}
*/



