#include <stdio.h>
#define x 10
#undef x
int main()
{
 #define x 25
 printf("x is %d",x);
}