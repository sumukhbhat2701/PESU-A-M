#include<stdio.h>
int main()
{
int a[4],i,avg,sum=0;
printf("enter values\n");
for(i=0;i<4;i++)
scanf("%d",&a[i]);
for(i=0;i<4;i++){
sum=sum+a[i];

}
avg=sum/4;
printf("%d",avg);
}
