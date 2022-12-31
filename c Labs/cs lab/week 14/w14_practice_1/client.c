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
    int choice,p=1,status=1;
    while(status)
    {
    printf("---------------------------------------------------------\n1:Delete node at the beginning\n
    2:Delete node at the end\n3:Display all nodes' data\n4:Product of all nodes' data\n5:Search data\n
    6:quit\n---------------------------------------------------------\n");
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
        case 4:p=productall(head);
        printf("Product of all nodes' data=%d\n",p);
        p=1;
        break;
        case 5:search(head);
        break;
        case 6:status=0;
        break;
        default:printf("Enter a choice between 1 and 8 only\nTry again!\n");

    }
    }
    free(head);
    free(temp);
    free(newnode);
    return 0;
}
