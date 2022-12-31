#include <stdio.h>
#define x 10
#undef x
int main()
{
 int x1=x;
 printf("x1 is %d",x1);
}