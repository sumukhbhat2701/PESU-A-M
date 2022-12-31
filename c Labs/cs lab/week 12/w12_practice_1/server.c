#include<stdio.h>
#include<stdlib.h>
#include "server.h"
void display(struct course *c,int n)
{
    printf("----------------------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
    printf("Course code:%d\tCourse name:%s\n",(c+i)->coursecode,(c+i)->coursename);
    }
    printf("----------------------------------------------------------------------\n");

}
void read(struct course *c,int n)
{
    for(int i=0;i<n;i++)
    {
    printf("Enter course code:");
    scanf("%d",&((c+i)->coursecode));
    printf("Enter course name:");
    scanf("%s",(c+i)->coursename);
    }
    printf("\n");
}