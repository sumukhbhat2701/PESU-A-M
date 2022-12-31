#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = NULL;
	return temp;
}

void List_initialize(List* ptr_List) 
{
//TODO
	ptr_List->head = NULL;
	ptr_List->number_of_Nodes = 0;  	
}

void List_insert_front(List* ptr_List, int data) 
{
//TODO	
    Node *new = create_Node(data,ptr_List->head);
    if(ptr_List->head == NULL) 
  {
      ptr_List->head=new;
  }
  else 
  {
	    new->link = ptr_List->head;
		ptr_List->head=new;
  }
  ptr_List->number_of_Nodes+=1;
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO
    return Node_ptr->data; 
}

void List_delete_front(List* ptr_List)
{
	//TODO
    Node *last;
	if(ptr_List->head==NULL) {
		//EMPTY
	}
	else{
			last=ptr_List->head;
			ptr_List->head=last->link;
            // printf("POPPED=%c\n",last->data);   
			free(last);
		}
    ptr_List->number_of_Nodes-=1;
}

void List_destroy(List* ptr_List) 
{
	//TODO
    Node *p1=ptr_List->head;
    Node *p2=NULL;
    while(p1!=NULL)
    {
        p2=p1;
        p1=p1->link;
        free(p2);
    }
    free(ptr_List);
}


void Stack_initialize(Stack *ptr_Stack) 
{
	// TODO
    ptr_Stack->ptr_List = (List *)malloc(sizeof(List));
    List_initialize(ptr_Stack->ptr_List);
}

void Stack_push(Stack *ptr_Stack, int key)
{
	// TODO
	List_insert_front(ptr_Stack->ptr_List,key);
}

void Stack_pop(Stack *ptr_Stack) 
{
	// TODO
    List_delete_front(ptr_Stack->ptr_List);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
	// TODO
    if(ptr_Stack->ptr_List->head!=NULL){
        return 0;
    }
    else
    {
        return 1;
    }
}

const int Stack_peek(Stack *ptr_Stack)
{
	// TODO
    return Node_get_data(ptr_Stack->ptr_List->head);
}

void Stack_destroy(Stack *ptr_Stack) 
{
	// TODO
    List_destroy(ptr_Stack->ptr_List);
    free(ptr_Stack);
}

int exponent(int x,int y){ //to calculate x^y
	int prod=1,count=1;
	while(count<=y){
		prod = prod*x;
		count++;
	}
	return prod;

}

int postfix_eval(const char* expression) 
{
    // TODO
	int res,op1,op2;
	Stack *stack = (Stack *)malloc(sizeof(Stack));
    Stack_initialize(stack);
	 
	for(int i=0;expression[i]!='\0';i++)
	{
		char ch=expression[i];
		if (ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='^')
		{
			op1 = Stack_peek(stack);
			Stack_pop(stack);
			op2 = Stack_peek(stack);
			Stack_pop(stack);
			
			if(ch=='+') res = op1+op2; 
			else if(ch=='-') res = op2-op1;
			else if(ch=='*') res = op1*op2;
			else if(ch=='/') res = op2/op1;
			else if(ch=='^') res = exponent(op2,op1);

			Stack_push(stack,res);
		}
		else Stack_push(stack,ch-'0');
	}
	res = Stack_peek(stack);
	Stack_pop(stack);
	Stack_destroy(stack);
	return res;
}
