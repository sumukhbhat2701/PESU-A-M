#include<stdio.h>
int main()
{
int a[10],i;
printf("enter values\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
printf("entered values are:\n");
for(i=0;i<10;i++)
printf("%d",a[i]);
}