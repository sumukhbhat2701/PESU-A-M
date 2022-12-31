#include<stdio.h>
int main()
{
int a[6]={3,3,5,2,1,2},b[5];
/*for(int i=0;i<5;i++)
b[i]=a[i];
printf("copied elements are\n");
for(int i=0;i<5;i++)
printf("%d",b[i]);*/

for(int i=0;i<=6;i++)
if(a[i]==a[i+1])
{
printf("duplicate elements is %d\n",a[i]);
i++;
}


}
