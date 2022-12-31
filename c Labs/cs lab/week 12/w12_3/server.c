#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "server.h"
void read(struct student *a,int n)
{
    for(int i=0;i<n;i++)
    {
    printf("Enter the student-%d details:\n",i+1);
    printf("Enter student roll number:");
    scanf("%d",&(a+i)->rno);
    printf("Enter student-name:");
    scanf("%s",(a+i)->name);
    printf("Enter student marks:");
    scanf("%d",&(a+i)->marks);
    printf("---------------------------------------------\n");
    }
}
void display(struct student *a,int n)
{
    printf("rollnumber          name          marks\n");
    printf("---------------------------------------------\n");
    for(int i=0;i<n;i++)
    {    printf("%d                  %s            %d\n",(a+i)->rno,(a+i)->name,(a+i)->marks);;
    printf("---------------------------------------------\n");
    }
}
void sort(struct student *a,int n)
{
    int *marksort,rnoswap,markswap;
    char nameswap[100];
    marksort=(int *)malloc(n*sizeof(int));
    if(marksort!=NULL)
    {
        for(int i=0;i<n;i++)
        {
            *(marksort+i)=((a+i)->marks);
        }
        for (int c = 0 ; c < n - 1; c++)
        {
            for (int d = 0 ; d < n - c - 1; d++)
                {
                    if (*(marksort+d) < *(marksort+d+1))
                        {
                            rnoswap       = (a+d)->rno;
                            (a+d)->rno   = (a+d+1)->rno;
                            (a+d+1)->rno = rnoswap;
                            strcpy(nameswap,((a+d)->name));
                            strcpy(((a+d)->name),((a+d+1)->name));
                            strcpy(((a+d+1)->name),nameswap);
                            markswap       = (a+d)->marks;
                            (a+d)->marks   = (a+d+1)->marks;
                            (a+d+1)->marks = markswap;
                        }
                }
        }
    }
    else
        printf("Sorting error!\n");
    free(marksort);
}