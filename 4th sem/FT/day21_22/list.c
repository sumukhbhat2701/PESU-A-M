#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head = ptr_list->tail = NULL;
}

void disp_list(const list_t *ptr_list)
{
	node_t* temp = ptr_list->head;
	while(temp != NULL)
	{
		disp_state(&temp->st);
		temp = temp->next;
	}
}

void add_at_end(list_t *ptr_list, const state_t *ptr_state)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->st = *ptr_state;
	temp->next = NULL;
	// empty list
	if(ptr_list->head == NULL)
	{
		temp->prev = ptr_list->tail;
		ptr_list->head = ptr_list->tail = temp;
	}
	else // has # of nodes
	{
		temp->prev = ptr_list->tail;
		ptr_list->tail = ptr_list->tail->next = temp;
	}
	
}

void remove_at_end(list_t *ptr_list)
{
	// empty
	if(ptr_list->head == NULL)
	{
		printf("list empty; cannot remove\n");
	}
	else if(ptr_list->head == ptr_list->tail ) // one node
	{
		free(ptr_list->tail);
		ptr_list->head = ptr_list->tail = NULL;
	}
	else
	{
		node_t* temp = ptr_list->tail;
		ptr_list->tail = ptr_list->tail->prev;
		ptr_list->tail->next = NULL;
		free(temp);
	}
}

int is_repeated(const list_t *ptr_list, const state_t *ptr_state)
{
	node_t* temp = ptr_list->head;
	while(temp != NULL)
	{
		if(are_same(ptr_state, &temp->st))
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

