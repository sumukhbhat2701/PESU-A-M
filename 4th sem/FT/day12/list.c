#if 0
#include <stdio.h>
#include "list.h"
#include <stdlib.h>

#define ALLOC(X) (X*)malloc(sizeof(X))

void init_list(list_t *ptr_list)
{
	// ptr_list = NULL; // TERRIBLE
	ptr_list->head_ = NULL;
}
	
// ordered list:
//  insert into empty list
//	insert in the beginning
//			at the end
//			in the middle

node_t* create_node(int key)
{
	node_t *temp = ALLOC(node_t);
	temp->key_ = key;
	temp->link_ = NULL;
	return temp;
}

void insert_list(list_t *ptr_list, int key)
{
	node_t *temp = create_node(key);
	// empty list
	if(ptr_list->head_ == NULL)
	{
		ptr_list->head_ = temp;
		temp->link_ = NULL;
	}
	else
	{
		// traverse the list; find the posn and insert
		node_t *prev = NULL;
		node_t *pres = ptr_list->head_;
		while(pres != NULL && pres->key_ < temp->key_)
		{
			prev = pres;
			pres = pres->link_;
		}
		// add in the beginning
		if(prev == NULL)
		{
			ptr_list->head_ = temp;
			temp->link_ = pres;
		}		
		else // middle or end
		{
			prev->link_ = temp;
			temp->link_ = pres;
		}

	}
}

void disp_list(const list_t *ptr_list)
{
	node_t *temp = ptr_list->head_;
	while(temp)
	{
		printf("%d ", temp->key_);
		temp = temp->link_;
	}
	printf("\n");
}
#endif

// header node : empty list has one node
#include <stdio.h>
#include "list.h"
#include <stdlib.h>

#define ALLOC(X) (X*)malloc(sizeof(X))
node_t* create_node(int key)
{
	node_t *temp = ALLOC(node_t);
	temp->key_ = key;
	temp->link_ = NULL;
	return temp;
}

void init_list(list_t *ptr_list)
{
	ptr_list->head_ = create_node(1729);
}
	
// ordered list:
//  insert into empty list
//	insert in the beginning
//			at the end
//			in the middle



void insert_list(list_t *ptr_list, int key)
{
	node_t *temp = create_node(key);
	// traverse the list; find the posn and insert
	node_t *prev = ptr_list->head_;
	node_t *pres = ptr_list->head_->link_;
	while(pres != NULL && pres->key_ < temp->key_)
	{
		prev = pres;
		pres = pres->link_;
	}
	prev->link_ = temp;
	temp->link_ = pres;
}

void disp_list(const list_t *ptr_list)
{
	node_t *temp = ptr_list->head_->link_;
	while(temp)
	{
		printf("%d ", temp->key_);
		temp = temp->link_;
	}
	printf("\n");
}

