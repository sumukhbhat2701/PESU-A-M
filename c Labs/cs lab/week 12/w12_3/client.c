#include<stdio.h>
#include<stdlib.h>
#include "server.h"
int main()
{
    struct student *a;
    int n;
    printf("Enter number of students:");
    scanf("%d",&n);
    a=(struct student *)malloc(n*sizeof(struct student));
    if(a==NULL)
    {
        printf("MEMORY ALLOCATION ERROR!\n");
    }
    else{
    read(a,n);
    printf("Before sorting:\n");
    printf("---------------------------------------------\n");
    display(a,n);
    sort(a,n);
    printf("After sorting:\n");
    printf("---------------------------------------------\n");
    display(a,n);
    }
    free(a);
    return 0;
}