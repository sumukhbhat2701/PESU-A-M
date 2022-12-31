#include<stdio.h>
#include<stdlib.h>
#include "server.h"
int sumall(struct node *head)
{
    int sum=0;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        sum=sum+(temp->data);
        temp=temp->next;
    }
    return sum;
}
int sumeven(struct node *head)
{
    int sum=0;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if((temp->data)%2==0)
        sum=sum+(temp->data);
        temp=temp->next;
    }
    return sum;
}
int sumodd(struct node *head)
{
    int sum=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if((temp->data)%2!=0)
        sum=sum+(temp->data);
        temp=temp->next;
    }
    return sum;
}
int sumalternate(struct node *head)
{
    int sum=0,count=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(count%2==0)
        {
        sum=sum+(temp->data);
        }
        count++;
        temp=temp->next;
    }
    return sum;
}
void display(struct node *head)
{
    struct node *temp=head; 
    int d,i=1;
    while(temp!=NULL)
    {
        d=(temp->data);
        temp=temp->next;
        printf("node-%d:%d\n",i,d);
        i++;
    }
    if(i==1 && temp==NULL)
    {
        printf("Linked list is empty!\n");
    }
}
struct node* beg(struct node *head)
{
	struct node *p;
    int value;
    printf("Enter the data to be inserted:");
    scanf("%d",&value);
	p=malloc(sizeof(struct node));
	p->data=value;
	p->next=head;
    printf("Insertion successful!\n");
	return (p);
}
struct node* end(struct node *head)
{
    int new_data;
    printf("Enter data to be inserted:");
    scanf("%d",&new_data);
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    struct node *last = head; 
   
    new_node->data  = new_data; 
  
    new_node->next = NULL; 
  
    if (head == NULL) 
    { 
       head = new_node; 
       return(head);
    }   
       
    while (last->next != NULL) 
        last = last->next; 
       last->next = new_node; 
    printf("Insertion successful!\n");
    return head;
}