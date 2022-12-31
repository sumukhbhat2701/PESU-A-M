#include <stdio.h>
#define max(x,y) x>y?x:y
int main()
{
 int a,b;
 a=10;b=12;
 printf("Maximum of %d & %d is %d",a,b,max(a,b));
}