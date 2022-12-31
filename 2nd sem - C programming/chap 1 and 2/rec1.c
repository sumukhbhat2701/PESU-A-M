//sum of n natural numbers
#include<stdio.h>
int sum(int);
int main()
{
int num,r;
printf("enter a number");
scanf("%d",&num);
r=sum(num);   //function call
printf("%d",r);
}
int sum(int n)
{
if(n!=0)
{
return n+sum(n-1); //recurcive function
}
else
{
return n;  //base condition
}
}