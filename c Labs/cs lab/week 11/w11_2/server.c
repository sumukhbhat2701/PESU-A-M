#include<stdio.h>
#include "server.h"
void input(struct student *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Input student-%d details:\n",i+1);
        printf("Enter student SRN:");
        scanf("%d",&a[i].srn);
        printf("Enter student name:");
        scanf("%s",a[i].name);
        printf("Enter physics marks:");
        scanf("%d",&a[i].phym);
        printf("Enter math marks:");
        scanf("%d",&a[i].mathm);
        printf("Enter electronics marks:");
        scanf("%d",&a[i].ecem);
        printf("Enter problem solving with c marks:");
        scanf("%d",&a[i].pswcm);
        printf("Enter mechanics marks:");
        scanf("%d",&a[i].mechm);
        printf("--------------------------------------------------------\n");
     }  
}
void output(struct student *a,int n)
{
    float avg;
    for(int i=0;i<n;i++)
    {
        printf("Student-%d details:\n",i+1);
        printf("Student SRN:%d\n",a[i].srn);
        printf("Student name:%s\n",a[i].name);
        printf("Physics marks:%d\n",a[i].phym);
        printf("Math marks:%d\n",a[i].mathm);
        printf("Electronics marks:%d\n",a[i].ecem);
        printf("Problem solving with c marks:%d\n",a[i].pswcm);
        printf("Mechanics marks:%d\n",a[i].mechm);
        printf("Total marks:%d\n",a[i].phym+a[i].mathm+a[i].ecem+a[i].pswcm+a[i].mechm);
        avg=(a[i].phym+a[i].mathm+a[i].ecem+a[i].pswcm+a[i].mechm)/5.0;
        printf("Average marks:%.2f\n",avg);
        if(avg>=85 && avg<=100)
        printf("Division:FIRST CLASS WITH DISTINCTION\n");
        else if(avg>=60 && avg<=84)
        printf("Division:FIRST CLASS\n");
        else if(avg>=50 && avg<=59)
        printf("Division:SECOND CLASS\n");
        else if(avg>=40 && avg<=49)
        printf("Division:THIRD CLASS\n");
        else
        printf("Division:FAIL\n");
        if(avg>=40)
        printf("RESULT:PASS\n");
        else
            printf("Result:FAIL\n"); 
        
        printf("--------------------------------------------------------\n");
     }  
}