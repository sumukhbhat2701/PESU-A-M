#include<stdio.h>
#include "server.h"
void input(struct items *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Input item-%d details:\n",i+1);
        printf("Enter item quantity:");
        scanf("%d",&a[i].quantity);
        printf("Enter item unit price:");
        scanf("%d",&a[i].unit_price);
        printf("--------------------------------------------------------\n");
     }  
}
void output(struct items *a,int n)
{
    int total,sum=0;
    for(int i=0;i<n;i++)
    {
        a[i].tot_cost=a[i].quantity*a[i].unit_price;
        printf("Item-%d details:\n",i+1);
        printf("Item quantity:%d\n",a[i].quantity);
        printf("Item unit price:%d\n",a[i].unit_price);
        printf("Item total cost:%d\n",a[i].tot_cost);
        printf("--------------------------------------------------------\n");
        sum=sum+a[i].tot_cost;
     }  
     printf("Total bill amount:%d\n",sum);
}