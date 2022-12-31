#include "6b.h"

stack* stack_initialize(int size)
{
//TODO
    stack *Stack_ptr = (stack *)malloc(sizeof(stack));
    Stack_ptr->arr = (int *)malloc(size*sizeof(int));
	Stack_ptr->top = -1;
    return Stack_ptr;
}

void stack_push(stack *ptr_stack, int key) 
{
//TODO
	// printf("BEFORE PUSH:TOP=%d",(ptr_stack->top));
    (ptr_stack->top)++;
	// printf("AFTER PUSH:TOP=%d",(ptr_stack->top));
	*((ptr_stack->arr)+(ptr_stack->top)) = key; 
}

void stack_pop(stack *ptr_stack)
{
//TODO
    // char ch = ptr_stack->arr[(ptr_stack->top)];
	// printf("BEFORE POP:TOP=%d",(ptr_stack->top));
	(ptr_stack->top)--;
	// printf("AFTER POP:TOP=%d",(ptr_stack->top));
}

int stack_is_empty(stack *ptr_stack)
{
//TODO
    if(ptr_stack->top==-1)
    {
        return 0;
    }
    else return 1;
}

int stack_peek(stack *ptr_stack) 
{
//TODO
	// printf("BEFORE PEEK:TOP=%d",(ptr_stack->top));
    return(*((ptr_stack->arr)+(ptr_stack->top)));

}

void stack_destroy(stack *ptr_stack) 
{
//TODO
    free(ptr_stack->arr);
    free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
//TODO
    stack *Stack = stack_initialize(strlen(source_infix));
	char ch;
	int i,j,inp_prec,stk_prec;
	stack_push(Stack,'#');

	for(i=0,j=0;source_infix[i]!='\0';i++)
	{
		ch = source_infix[i];
		// printf("%c%d",sym,i);
		// printf("%c",stack_peek(Stack));

		switch(ch)
		{
			case '-':
			case '+': inp_prec = 10;break;
			case '/':
			case '*': inp_prec = 30;break;
			case '^': inp_prec = 60;break;
			case '(': 
			case '{':
			case '[': inp_prec = 90;break;
			case ')': 
			case ']':
			case '}': inp_prec = 0;break;
			default : inp_prec = 70;
		}

		switch(stack_peek(Stack))
		{
			case '-':
			case '+': stk_prec = 20;break;
			case '/':
			case '*': stk_prec = 40;break;
			case '^': stk_prec = 50;break;
			case '(': 
			case '[':
			case '{': stk_prec = 0;break;
			case '#': stk_prec = -10;break;
			default : stk_prec = 80;
		}

		while(stk_prec > inp_prec)
		{	 
			// printf("\nSTACK_PEEK=%c\nSTACK_PREC=%d\nINPUT_PREC=%d\nJ=%d\n",stack_peek(Stack),stack_prec(stack_peek(Stack)),input_prec(sym),j);
			
			*(target_postfix+(j++)) = stack_peek(Stack);
			stack_pop(Stack);

			switch(stack_peek(Stack))
			{
			case '-':
			case '+': stk_prec = 20;break;
			case '/':
			case '*': stk_prec = 40;break;
			case '^': stk_prec = 50;break;
			case '(': 
			case '[':
			case '{': stk_prec = 0;break;
			case '#': stk_prec = -10;break;
			default : stk_prec = 80;
			}
		}
		
		if(stk_prec!=inp_prec)
		{	
			stack_push(Stack,ch);
		}	
		else 
		{
			stack_pop(Stack);
		}
    }
	
	while(stack_peek(Stack)!='#')
	{	
		*(target_postfix+(j++)) =stack_peek(Stack);
		stack_pop(Stack);
	}
    *(target_postfix+j) ='\0';
	stack_destroy(Stack);
}
