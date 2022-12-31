#include<stdio.h>
#include<stdlib.h>
#include "server.h"
int main()
{
    struct course *c;
    int n;
    c=(struct course *)malloc(6*sizeof(struct course));
    printf("Enter the 6 courses for first sem:\n");
    read(c,6);
    printf("Courses of first sem:\n" );
    display(c,6);
    printf("Enter the number of courses to be dropped:");
    scanf("%d",&n);
    c=realloc(c,(6-n)*sizeof(struct course));
    printf("Enter the %d new courses for second sem:\n",(6-n));
    read(c,6-n);
    printf("New Courses of second sem:\n" );
    display(c,6-n);
    free(c);
    return 0;
}