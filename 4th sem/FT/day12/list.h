#if 0
#ifndef LIST_H
#define LIST_H
struct node
{
	int key_;
	struct node* link_;
};
typedef struct node node_t;
struct list
{
	node_t *head_;
};
typedef struct list list_t;
// typedef : create an interface

void init_list(list_t *ptr_list);
void insert_list(list_t *ptr_list, int key);
void disp_list(const list_t *ptr_list);
#endif
#endif

// header node based implementation
#ifndef LIST_H
#define LIST_H
struct node
{
	int key_;
	struct node* link_;
};
typedef struct node node_t;
struct list
{
	node_t *head_;
};
typedef struct list list_t;
// typedef : create an interface

void init_list(list_t *ptr_list);
void insert_list(list_t *ptr_list, int key);
void disp_list(const list_t *ptr_list);
#endif


/*
// did not use header node
node_t* search(const list_t *ptr_list, int key)
{
	node_t* pres = ptr_list->head_;
	while(pres != NULL && pres->key_ == key)
	{
		pres = pres->link_;
	}
	return pres;
}

// tailer node :
//	copy the key to the tailer node
//	list_t => head_, tail_

node_t* search(const list_t *ptr_list, int key)
{
	node_t* pres = ptr_list->head_;
	ptr_list->tail_->key_ = key;
	while(pres->key_ == key)
	{
		pres = pres->link_;
	}
	return (pres == ptr_list->tail) ? NULL : pres;
}
*/

