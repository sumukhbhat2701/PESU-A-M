#include "5a.h"
#include<stdlib.h>

static Node* create_Node(int data, Node* link)
 {
// TODO - create and allocate dynamic space
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->link = NULL;
    return new;
}

void list_initialize(List* ptr_list) 
{
//TODO - initialize structure members to default values
	ptr_list->head = NULL;
	ptr_list->number_of_Nodes = 0;    
}


void list_insert_front(List* ptr_list, int data) 
{
//TODO - perform linked list implementation of push operation.4
    Node *new = create_Node(data,ptr_list->head);
    if(ptr_list->head == NULL) 
  {
      ptr_list->head=new;
  }
  else 
  {
	    new->link = ptr_list->head;
		ptr_list->head=new;
  }
  ptr_list->number_of_Nodes+=1;
    
}


const int Node_get_data(Node *Node_ptr) 
{
//TODO - return the top most element
    return Node_ptr->data; 
}


void list_delete_front(List* ptr_list) 
{
//TODO - perform linked list implementation of pop operation.
    Node *last;
	if(ptr_list->head==NULL) {
		//EMPTY
	}
	else{
			last=ptr_list->head;
			ptr_list->head=last->link;
            // printf("POPPED=%c\n",last->data);   
			free(last);
		}
    ptr_list->number_of_Nodes-=1;
}


void list_destroy(List* ptr_list) 
{
//TODO - free the allocated space
    Node *p1=ptr_list->head;
    Node *p2=NULL;
    while(p1!=NULL)
    {
        p2=p1;
        p1=p1->link;
        free(p2);
    }
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
//TODO - get the memory allocation for stack, and intern call list initialize
    ptr_Stack->ptr_list = (List *)malloc(sizeof(List));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
//TODO	 - call the function list_insert_front
    list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack *ptr_Stack) 
{
//TODO- call the function list_delete_front
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
//TODO	- return 0 if stack is not empty
    if(ptr_Stack->ptr_list->head!=NULL){
        return 0;
    }
    else
    {
        return 1;
    }
    
}

const int Stack_peek(Stack *ptr_Stack) 
{
//TODO	- return the top most element of the stack
    return Node_get_data(ptr_Stack->ptr_list->head);
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
    list_destroy(ptr_Stack->ptr_list);
    free(ptr_Stack);
 }

int match_parenthesis(const char* string)
{
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    Stack_initialize(stack);
    for(int i=0;string[i]!='\0';i++){
        if(string[i]=='(' || string[i]=='[' || string[i]=='{'){
            Stack_push(stack,string[i]);
            // printf("PUSHED=%c\n",string[i]);
        }
        else if((string[i]==')' || string[i]==']' || string[i]=='}') && Stack_is_empty(stack)==0){
            if ((string[i]==')' && Stack_peek(stack)!='(') || (string[i]==']' && Stack_peek(stack)!='[') || (string[i]=='}' && Stack_peek(stack)!='{'))
            {
                Stack_destroy(stack);
                return 0;
            }    
            Stack_pop(stack); 
        }
        else
        {
            Stack_destroy(stack);
            return 0;
        }
        
    }
    if(Stack_is_empty(stack)==0){
        Stack_destroy(stack);
        return 0;
    }
    Stack_destroy(stack);
    return 1;

}
