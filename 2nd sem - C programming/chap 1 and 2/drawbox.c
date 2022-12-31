#include<stdio.h>
void draw_box(int wi,int hi)
{
for(int i=0;i<wi;++i)
{
printf("*");
}
for(int i=0;i<hi-2;++i)
{
printf("\n*");
for(int j=0;j<wi-2;++j)
{
printf(" ");
}
printf("*");
}
printf("\n");
for(int i=0;i<wi;++i)
printf("*");
}

int main()
{
int hi,wi;
scanf("%d%d",&hi,&wi);
if(hi<3)
printf("less then 3\n");
if(wi<3)
printf("less than 3\n");
draw_box(wi,hi);
}