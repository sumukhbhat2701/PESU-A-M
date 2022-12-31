#include<stdio.h>
int main()
{
int n,c,sum=0;
printf("enter n number\n");
scanf("%d",&n);
for(c=1;c<=n;c++)
{
sum=sum+c;
}
printf("%d\n",sum);
return 0;
}