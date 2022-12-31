#include<stdio.h>
#include<stdlib.h>
#include "server.h"
int main()
{
    int *a,n;
    printf("Enter size of array:");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("MEMORY ALLOCATION ERROR!\n");
    }
    else{
    read(a,n);
    printf("Before Sorting:\n");
    display(a,n);
    sort(a,n);
    printf("After Sorting:\n");
    display(a,n);
    }
    free(a);
    return 0;
}