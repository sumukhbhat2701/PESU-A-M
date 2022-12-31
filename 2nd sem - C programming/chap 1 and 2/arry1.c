#include<stdio.h>
int main()
{
int a[5];   //declaration
int i;
printf("enter values\n");
for(i=0;i<5;i++)
scanf("%d",&a[i]); //for taking input 
printf("entered values\n");
for(i=0;i<5;i++)
printf("%d\n",a[i]); //for displaying output array
}
