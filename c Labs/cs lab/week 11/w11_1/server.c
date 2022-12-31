#include<stdio.h>
#include "server.h"
void compare(struct date a,struct date b)
{
    if(a.day==b.day && a.month==b.month && a.year==b.year)
       printf("%d/%d/%d and %d/%d/%d are equal\n",a.day,a.month,a.year,b.day,b.month,b.year);                          
    else if (a.year > b.year || a.year == b.year && a.month > b.month || a.year == a.year && a.month == b.month && a.day > b.day)
        printf("%d/%d/%d is greater than %d/%d/%d\n",a.day,a.month,a.year,b.day,b.month,b.year); 
    else
        printf("%d/%d/%d is lesser than %d/%d/%d\n",a.day,a.month,a.year,b.day,b.month,b.year); 

       
}