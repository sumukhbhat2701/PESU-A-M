#include<stdio.h>
int add(int,int); //function declaration
int main()
{
int x=4,y=6;
int s;
printf("addition\n");
s=add(x,y); //function call with list of arguments
printf("ended %d\n",s);
}

int add(int a,int b)
{
int sum;
sum=a+b;
printf("%d\n",sum);
return sum;
}
