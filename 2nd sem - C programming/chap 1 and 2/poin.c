#include<stdio.h>
int main()
{
int a=10;
int* p; //pointer variable
p=&a;
printf("%d\n",a);
printf("%d\n%d\n%d\n%d",p,&a,&p,*p);
}