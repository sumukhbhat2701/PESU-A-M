#include<stdio.h>
#include "server.h"
int main()
{
    struct complex z1,z2;
    printf("Enter complex number 1:");
    scanf("%d+%di",&z1.real,&z1.img);
    printf("Enter complex number 2:");
    scanf("%d+%di",&z2.real,&z2.img);
    add(z1,z2);
    sub(z1,z2);
    mul(z1,z2);
    return 0;
}