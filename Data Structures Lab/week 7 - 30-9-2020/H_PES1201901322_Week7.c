#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
	node* new =  (node*)malloc(sizeof(node));
	new -> time = time;
	new -> id = id; 
	new -> link = NULL;
	return new;
}
void list_initialize(List *ptr_list)
{
//TODO
	ptr_list -> head = NULL;
	ptr_list -> tail = NULL;
	ptr_list -> number_of_nodes = 0;  
}
const int node_get_id(node *node_ptr)
{
//TODO	
	return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
//TODO		
	return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
//TODO	
	node *new = create_node(id,time,ptr_list->head);
	if(ptr_list->head == NULL) 
	{
		ptr_list->head = new;
		ptr_list->tail = new;
	}
	else 
	{
		ptr_list->tail->link = new;
		ptr_list->tail = new;
	}
	ptr_list->number_of_nodes+=1;
}

void list_delete_front(List *ptr_list)
{
//TODO	
	if(ptr_list->head == NULL) {
		//EMPTY queue
	}
	else
	{
		node *front_node = ptr_list->head;
		ptr_list->head = front_node->link;   
		free(front_node);
		ptr_list->number_of_nodes-=1;
	}
    
}

void list_destroy(List *ptr_list)
{
//TODO	
	node *forward = ptr_list->head;
    node *backward = NULL;
    while(forward != NULL)
    {
        backward = forward;
        forward = forward->link;
        free(backward);
    }
    free(ptr_list);
}

void queue_initialize(Queue *queue_list)
{
//TODO
	queue_list->ptr_list = (List *)malloc(sizeof(List));
    list_initialize(queue_list->ptr_list);	
}

void queue_enqueue(Queue *ptr, int id, int time)
{
//TODO	
	list_insert_rear(ptr->ptr_list,id,time);
}

void queue_dequeue(Queue *ptr)
{
//TODO		
	list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
//TODO	
	if(ptr->ptr_list->head == NULL)
	{
		return 1;
	}	
	else
	{
		return 0;
	}
	
}

void queue_peek(Queue *ptr)
{
//TODO
	if(queue_is_empty(ptr)==1)
	{
		printf("Empty Queue\n");
	}
	else
	{
		printf("%d %d\n",ptr->ptr_list->head->id,ptr->ptr_list->head->time);
	}
			
}

void queue_destroy(Queue *ptr)
{
//TODO	
	list_destroy(ptr->ptr_list);
    free(ptr);	
}

const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO		
	struct node *forward = ptr_queue->ptr_list->head;
	struct node *backward = NULL;	
	int cum_sum = 0;  
	if(queue_is_empty(ptr_queue) == 1){
		printf("Empty Queue\n");
		return 0;
	}
	while (forward!=NULL)
	{  
		if(cum_sum < t)
		{

			backward = forward;  
			cum_sum += forward->time;
			forward = forward->link;
			if(cum_sum < t){
				queue_dequeue(ptr_queue); 
			}		 
		}
		if(cum_sum >= t)
		{                
			printf("%d\n",backward->id);
			return 1;
		}
	}     
	if(queue_is_empty(ptr_queue) == 1)
	{        
		printf("Empty Queue\n");
		return 0;
	}	
}

// void list_destroy(List *ptr_list)
// {
// //TODO
// }
