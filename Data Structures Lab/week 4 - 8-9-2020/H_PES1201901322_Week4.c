#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
//TODO
    if(pos==0)
	{
        Node* new = (Node *)malloc(sizeof(Node));
        new->data = data;
        new->next = NULL;
        if((cll->head)==NULL)
        {
            cll->head=new;
            new->next=new;
            cll->tail = new;
        }
        else
        {
            Node* prev;
            Node *new=(Node*)malloc(sizeof(Node));
            new->data=data;
            new->next=cll->head;
            prev=cll->head;
            while(prev->next!=cll->head)
                prev=prev->next;
            prev->next=new;
            cll->head=new;
        }
        cll->length++;
	}
	else if(pos==(cll->length))
	{
        Node* prev;
        Node* new = (Node *)malloc(sizeof(Node));
        new->data = data;
        new->next = NULL;
        
        if(cll->head==NULL)
        {
            cll->head=new;
            new->next=new;
            cll->tail = new;
        }
        else
        {	
            prev=cll->head;
            while(prev->next!=cll->head)
                prev=prev->next;
            prev->next=new;
            new->next=cll->head;
            cll->tail = new;
        }
        cll->length++;
	}
	else if(pos>0 && pos<(cll->length))
	{
		Node* new = (Node *)malloc(sizeof(Node));
        new->data = data;
        new->next = NULL;
        Node* prev,*temp;
        int i=0;
        temp=cll->head;
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        if(i==pos)
        {
            new->next=prev->next;
            prev->next=new;
        }
        cll->length++;
	}
	else
	{
		//OUT OF BOUNDS
	}
	
    

}

void position_delete(List* cll, int pos)
{
//TODO
    
    if(cll->head==NULL)
    {
        //EMPTY LIST
    }
    else if (pos==0)
    {
        Node *temp=cll->head;
        Node *last=cll->tail;
        cll->head=temp->next;
        last->next=cll->head;
        free(temp);
        cll->length--;
        if(cll->length==0){
            cll->head=NULL;
            cll->tail=NULL;
        }
       
    }
    
	else if (pos>0 && pos <= cll->length-1)
    {		
        Node *temp=cll->head;
        Node *prev=NULL;
        for(int i=0;i<=pos;i++)
        {
            if(i==pos)
            {
                prev->next=temp->next;
                free(temp);
                if(pos==cll->length-1)
                {
                    cll->tail=prev;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        cll->length--;
	}
    if(pos>=cll->length || pos<0)
    {
        //OUT OF BOUNDS
    }
   
	
} 




int josephus(List* cll, int k)
{
//TODO
    // Node *prev=cll->head,*cur=cll->head->next,*p=NULL;
    // while(cll->length>1){
    //     for(int i=0;i<k;i++){
    //     if(p==NULL){
    //         p=cll->head;
    //     }
    //     else{
    //         p=p->next;
    //     }
    //     prev=prev->next;
    //     cur=cur->next;
    //     }
    //     free(prev);
    //     cll->length--;
    //     p->next=cur;
    //     // p=prev;
    //     prev=cur;
    //     cur=cur->next;
    // }
    // return cll->head->data;

    int i=k+1;
    while(cll->length>1){
        position_delete(cll,i);
        i=(i+1)%(cll->length); //LOGIC USED : as deletion reduces the size of list and index count by one already, only i+1 is enough and not i+2 for alternative nodes
        
    }
    return cll->head->data;
        
}

