#include<stdio.h>
#include<stdlib.h>
#include "server.h"
int main()
{
    struct employee *a;
    int n;
    printf("Enter number of employees:");
    scanf("%d",&n);
    a=(struct employee *)malloc(n*sizeof(struct employee));
    if(a==NULL)
    {
        printf("MEMORY ALLOCATION ERROR!\n");
    }
    else{
    read(a,n);
    display(a,n);
    }
    free(a);
    return 0;
}