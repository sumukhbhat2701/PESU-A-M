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
void sort(int *a,int n)//insertion sort
{
        int i,j,min,temp;
        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
                if(*(a+j)<*(a+min))
                {
                    min=j;
                }
            }
            if(min!=i)
            {
                temp=*(a+i);
                *(a+i)=*(a+min);
                *(a+min)=temp;
            }
        } 
}