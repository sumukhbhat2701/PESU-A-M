#include<stdio.h>
#include "server.h"
int main()
{
    struct items a[100];
    int n;
    printf("Enter total number of items:");
    scanf("%d",&n);
    input(&a,n);
    output(&a,n);
    return 0;
}