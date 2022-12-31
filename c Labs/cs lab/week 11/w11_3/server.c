#include<stdio.h>
#include "server.h"
void add(struct meas d1,struct meas d2)
{
    int total=d1.f*12+d2.f*12+d1.i+d2.i;
    int ft=total/12;
    int it=total%12;
    printf("Total in feet=%d and in inches=%d\n",ft,it);
}
    