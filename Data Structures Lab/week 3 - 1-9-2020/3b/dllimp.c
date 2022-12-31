#include"dll.h"
#include<stdlib.h>
int count_nodes(List* dll)
{
	//TODO
    int count=0;
    if(dll->number_of_nodes == 0)
        count=0;
    else
    {
        Node* temp = dll->head;

        while(temp != NULL)
        {
            count+=1;
            temp = temp->next;
        }
    }
    return count;
    //OR just:
    //return dll->number_of_nodes;

}

void insert_front(List* dll, int data)
{
    //TODO
    Node *new =(Node*)malloc(sizeof(Node));
	new->data = data;
	new->prev=NULL;
	new->next=NULL;
	
  if(dll->head == NULL) 
  {
      dll->head=new;
  }
  else 
  {
	    new->next = dll->head;
		dll->head->prev = new;
		dll->head=new;
  }
  dll->number_of_nodes+=1;
}


void dllist_delete_beginning(List* list)
{
    //TODO
    Node *temp;
  	if(list->head == NULL) {
          //empty list
    }
	else {
		   temp=list->head;
		   if((list->head)->next==NULL)
		   { 
             list->head=NULL;
	         free(temp);
	       }
		   else {
			  list->head=(list->head)->next;
		      (list->head)->prev=NULL;
		      free(temp);
		   }
           list->number_of_nodes-=1;
	    }
}

void enddel(List *dl1)
{   Node *temp;

  if(dl1 == NULL) {
      //empty list!!!
  }
  else if(dl1->head->next==NULL){
    temp=dl1->head;
	dl1->head=NULL;
	free(temp);
    }
  else { 
    temp=dl1->head;
    while(temp->next!=NULL)
	   temp=temp->next;
	(temp->prev)->next = NULL;
	free(temp);
	}
}

void position_delete(List* dll, int pos)
{
    //TODO
    Node *temp;
    int length = dll->number_of_nodes;
    
    if (pos == 0)
    {
        dllist_delete_beginning(dll);
    }
    else if (pos == length-1)
    {
         enddel(dll);
         dll->number_of_nodes-=1;
    }

    else if(pos>0 && pos<length-1)
    {
        temp = dll->head;
        int flag=0;
        while(temp!=NULL){
            if(flag==pos){
                (temp->prev)->next = temp->next;
		        (temp->next)->prev = temp->prev;
		        free(temp);
                break;

            }
            else{
                temp = temp->next;
                flag++;
            }

        }
        dll->number_of_nodes-=1;
     }
     else if(pos<0 || pos>length-1){
         //NOT OF BOUNDS!!!!!
     }
     

}

int search_list(List* dll,int key)
{
    //TODO
    int flag=-1,i=0;
    if(dll->number_of_nodes == 0)
    {
    }
    else
    {
        Node* temp = dll->head;

        while(temp != NULL)
        {
            if(temp->data==key){
                return i;
                break;
            }
            i+=1;
            temp = temp->next;
        }
        
    }
    return flag;
    
}


void reverse_list(List* dll)
{
    //TODO
    struct Node *temp = NULL;   
    struct Node *current = dll->head; 
    
    if(dll->number_of_nodes!=0 || dll->number_of_nodes!=1){
        while (current  !=  NULL) 
        { 
        temp = current->prev; 
        current->prev = current->next; 
        current->next = temp;               
        current = current->prev; 
        }       

        if(temp != NULL ) 
        dll->head = temp->prev; 
    }
    
 
}


