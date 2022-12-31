#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[3][3]={0,1};
for(int i=0;i<3;i++)
{


printf("\n");
for(int j=0;j<3;j++)
{
printf("%d\t",x[i][j]);
}
printf("\n");
}
}