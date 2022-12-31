#include<stdio.h>
int add(int a,int b);
int main()
{
printf("cal");
add(3,4);
}
int add(int a,int b)
{
int sum;
sum=a+b;
printf("%d",sum);
return sum;
}