#include<stdio.h>
#include "server.h"
int main()
{
    struct date a,b;
    printf("Enter date1:");
    scanf("%d/%d/%d",&a.day,&a.month,&a.year);
    printf("Enter date2:");
    scanf("%d/%d/%d",&b.day,&b.month,&b.year);
    compare(a,b);
    return 0;
}