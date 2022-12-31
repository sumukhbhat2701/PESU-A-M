#include<stdio.h>
#include "server.h"
void read(int *a,int n)
{
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&*(a+i));
}
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",*(a+i));
    printf("\n");
}
void cyclic(int *a,int n)
{
        *(a+n) = *(a+0);
        for (int i = 0; i < n; ++i)
        {
            *(a+i) = *(a+i+1);
        } 
}