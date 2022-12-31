#include<stdio.h>
#include<stdlib.h>
#include "server.h"
int main()
{
    int *a,n;
    printf("Enter the number of elements of a array:");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    readarray(a,n);
    printf("Before squaring:\n");
    displayarray(a,n);
    square(a,n);
    printf("\nAfter squaring:\n");
    displayarray(a,n);
    free(a);
    return 0;
}