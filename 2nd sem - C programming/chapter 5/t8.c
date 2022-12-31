#include <stdio.h>
int div(int,int);
#define div(x,y) (x/y)
int main()
{
 int a=10;
 int b=20;
#undef div
 printf("a=%d\tb= %d\t %d",a,b,div(a,b));
 
 
}

int div(int x,int y)
{
	return (y/x);
}
