#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	//TODO

	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *last = list->head;
	new_node->data = data;
	new_node->link = NULL;
	if(list->head == NULL){
		list->head = new_node; 
	}
	else{
		while(last->link!=NULL){
		last = last->link;
	}
	last->link = new_node;
	}
    list->number_of_nodes+=1;
	
}

void list_delete_front(List* list) {
	//TODO
	Node *last;
	if(list->head==NULL) {
		//nothing as told
	}
	else{
			last=list->head;
			list->head=last->link;
			free(last);
            list->number_of_nodes-=1;
		}
}

void list_insert_at (List *list, int data, int position)
{
	//TODO
	Node *temp, *prev = NULL;
    int tmp;
    int length = list->number_of_nodes;
	Node *new = (Node *)malloc(sizeof(Node));
	Node *p_head = list->head;
	new->data = data;
    
    if (position == 0)
    {
        new->link = p_head;
        temp = new;
    }
    else if (position == length)
    {
         for (temp = p_head; temp != NULL;
                  prev=temp,temp=temp->link);
         prev->link = new;
         new->link = NULL;
         temp = p_head;
    }

    else
    {
        for (temp = p_head, tmp = 0; temp != NULL;tmp++, prev=temp,temp=temp->link)
        {
            if (tmp == position)
            {
                prev->link = new;
                new->link = temp;
                break;
            }
        }
        
        temp=p_head;
     }
     list->number_of_nodes+=1;

}

void list_reverse(List* list)
{
 	//TODO
	Node *prev = NULL; 
    Node *current = list->head; 
    Node *links = NULL; 
    while (current != NULL) 
    { 
        links = current->link; 
        current->link = prev; 
        prev = current; 
        current = links; 
    } 
    list->head = prev; 
}


