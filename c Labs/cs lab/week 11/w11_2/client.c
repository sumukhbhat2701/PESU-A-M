#include<stdio.h>
#include "server.h"
int main()
{
    struct student a[100];
    int n;
    printf("Enter number of students:");
    scanf("%d",&n);
    input(&a,n);
    output(&a,n);
    return 0;
}