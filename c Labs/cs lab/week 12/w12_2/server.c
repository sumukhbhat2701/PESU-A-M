#include<stdio.h>
#include "server.h"
void read(struct employee *a,int n)
{
    for(int i=0;i<n;i++)
    {
    printf("Enter the employee-%d details:\n",i+1);
    printf("Enter employee-id:");
    scanf("%d",&(a+i)->empid);
    printf("Enter employee-name:");
    scanf("%s",(a+i)->empname);
    printf("Enter employee-department:");
    scanf("%s",(a+i)->empdept);
    printf("---------------------------------------------\n");
    }
}
void display(struct employee *a,int n)
{
    for(int i=0;i<n;i++)
    {
    printf("The employee-%d details are:\n",i+1);
    printf("Employee id:%d\n",(a+i)->empid);
    printf("Employee name:%s\n",(a+i)->empname);
    printf("Employee department:%s\n",(a+i)->empdept);
    printf("---------------------------------------------\n");
    }
}