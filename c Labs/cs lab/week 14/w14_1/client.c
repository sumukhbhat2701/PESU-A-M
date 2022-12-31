#include<stdio.h>
#include<stdlib.h>
#include "server.h"
int main()
{
    int n;
    struct node *head=NULL,*newnode,*temp;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data of node-%d:",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;

        }
        else
        {
            (temp->next)=newnode;
            temp=newnode;
        }
        
    }
    int choice,sum=0,status=1;
    while(status)
    {
    printf("---------------------------------------------------------\n1:Insert new node at the beginning\n2:Insert new node at the end\n3:Display all nodes' data\n
    4:Sum of all nodes' data\n5:Sum of odd data\n6:Sum of even data\n7:Sum of alternate nodes' data\n8:quit
    \n---------------------------------------------------------\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:head=beg(head);
        break;
        case 2:head=end(head);
        break;
        case 3:display(head);
        break;
        case 4:sum=sumall(head);
        printf("Sum of all nodes' data=%d\n",sum);
        sum=0;
        break;
        case 5:sum=sumodd(head);
        printf("Sum of odd data=%d\n",sum);
        sum=0;
        break;
        case 6:sum=sumeven(head);
        printf("Sum of even data=%d\n",sum);
        sum=0;
        break;
        case 7:sum=sumalternate(head);
        printf("Sum of alternate nodes' data=%d\n",sum);
        sum=0;
        break;
        case 8:status=0;
        break;
        default:printf("Enter a choice between 1 and 8 only\nTry again!\n");

    }
    }
    free(head);
    free(temp);
    free(newnode);
    return 0;
}
