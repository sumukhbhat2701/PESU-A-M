#include<stdio.h>
#include "server.h"
int main()
{
    struct meas d1,d2;
    printf("Enter distance 1:\n");
    printf("In Feet:");
    scanf("%d",&d1.f);
    printf("In inches:");
    scanf("%d",&d1.i);
    printf("Enter distance 2:\n");
    printf("In Feet:");
    scanf("%d",&d2.f);
    printf("In inches:");
    scanf("%d",&d2.i);
    add(d1,d2);
    return 0;
}