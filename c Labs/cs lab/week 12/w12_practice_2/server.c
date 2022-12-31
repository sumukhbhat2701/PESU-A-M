#include<stdio.h>
#include "server.h"
void readarray(int *a,int n)
{
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&*(a+i));
    }
}
void displayarray(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}
void square(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        *(a+i)=((*(a+i))*(*(a+i)));
    }
}
    