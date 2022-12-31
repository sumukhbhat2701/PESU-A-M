#include<stdio.h>
int main()
{
int a[5]={4,6,34,23,7};
int max;
max=a[0];
for(int i=1;i<5;i++)
{
if(a[i]>max)
{
max=a[i];
}
}
printf("%d",max);
}
