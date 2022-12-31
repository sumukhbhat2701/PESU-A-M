#include<stdio.h>
int main()
{
int a=10;
int* p;
p=&a;
printf("%d\n%d\n%d\n%d\n%d\n",a,p,*p,&a);
}