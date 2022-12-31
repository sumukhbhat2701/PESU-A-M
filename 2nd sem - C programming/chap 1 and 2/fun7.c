#include<stdio.h>
int max(int,int);
int main()
{
int x,y,s;
printf("enter 2 values");
scanf("%d%d",&x,&y);
s=max(x,y);  //function call
printf("%d",s);
}


int max(int n,int m) //function definition
{
int s;
if (n>m)
{
return n;
}
else
{
return m;
}
printf("%d",s);
}

