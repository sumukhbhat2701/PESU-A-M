//Write a program in C to read n number of values in an array and //display it in reverse order.
#include<stdio.h>
int main()
{
int a[5],i;
printf("enter values\n");
for(i=0;i<5;i++)
scanf("%d",&a[i]);
printf("entered values\n");
for(i=4;i>=0;i--)
{
printf("%d\n",a[i]);
}

//printf("%d\n",a[i]);
}