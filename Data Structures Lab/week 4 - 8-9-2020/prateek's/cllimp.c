#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=data;
    if(pos>cll->length || pos<0)
    {
        return;
    }
    else if(cll->head==NULL)
    {
        cll->head=new;
        cll->tail=new;
        new->next=new;
        
    }
    else if (pos==0)
    {
        new->next=cll->head;
        cll->head=new;
        cll->tail=new;
    }    
        
    else if(pos==cll->length-1)
    {
        Node *last=cll->tail;
        new->next=last->next;
        last->next=new;
        cll->tail=new;
        
    }
    else
    {   Node *temp=cll->head;
        for(int i=0;i<=pos;i++)
        {
            if(i==pos-1)
            {
                new->next=temp->next;
                temp->next=new;
              
            }
            temp=temp->next;
        }
    }
    cll->length++;
    return;
    

}

void position_delete(List* cll, int pos)
{
    if(pos>=cll->length || pos<0)
    {
        return;
    }
    else if(cll->head==NULL)
    {
        return;
    }
    else if (pos==0)
    {
        Node *temp=cll->head;
        Node *last=cll->tail;
        cll->head=temp->next;
        last->next=cll->head;
        free(temp);
       
    }
    
	else if (pos <= cll->length && pos > 0)
    {		
        Node *temp=cll->head;
        Node *p=NULL;
        for(int i=0;i<=pos;i++)
        {
            if(i==pos)
            {
                p->next=temp->next;
                free(temp);
                if(pos==cll->length-1)
                {
                    cll->tail=p;
                }
                break;
            }
            p=temp;
            temp=temp->next;
        }
	}
    cll->length--;
}    


int josephus(List* cll, int k)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p=cll->head;
    while (cll->length!=1)
    {
        position_delete(cll,k+1);
        if(k==cll->length-1)
        {
            if(cll->length%2==0)
                k=0;
            else
                k=-1;                
        }
        else
            k++;       
    }
    p=p->next;
    return p->data;


}


