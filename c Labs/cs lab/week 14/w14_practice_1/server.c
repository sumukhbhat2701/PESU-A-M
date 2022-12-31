#include<stdio.h>
#include<stdlib.h>
#include "server.h"
int productall(struct node *head)
{
    int p=1;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        p=p*(temp->data);
        temp=temp->next;
    }
    return p;
}
void search(struct node *head)
{
    int status=-1,node=1,ele;
    printf("Enter the search element:");
    scanf("%d",&ele);
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if((temp->data)==ele)
        {
            status=node;
            break;
        }
        temp=temp->next;
        node++;
    }
    if(status==-1)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("%d found in node-%d from beginning\n",ele,node);
    }
    
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
    if (head == NULL) 
        return NULL; 
  
    struct node* temp = head; 
    head = head->next; 
  
    free(temp); 
    printf("Succesfully Deleted!\n");
    return head; 
}
struct node* end(struct node *p_head)
{
    struct node *p_cur, *p_prev;

    if (p_head != NULL)
    {
        if (p_head->next == NULL) 
        {
            free (p_head);
            p_head = NULL;
        }
        else
        {
            for (p_cur = p_head; p_cur->next != NULL; p_prev=p_cur,p_cur = p_cur->next)
                ;   
            p_prev -> next = NULL;        
            free (p_cur);
        }
    }
    printf("Succesfully Deleted!\n");
    return (p_head);
}
