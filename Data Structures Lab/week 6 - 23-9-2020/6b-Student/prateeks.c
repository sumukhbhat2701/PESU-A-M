#include "6b.h"
int input_prec(char op)
{
	if(op=='+' || op=='-') return 1;
	if(op=='/' || op=='*') return 3;
	if(op=='^') return 6;
	if(op=='{' || op=='[' || op=='(') return 9;
	if(op=='}' || op==']' || op==')') return 0;
	return 7;
}

int stack_prec(char op)
{
	if(op=='+' || op=='-') return 2;
	if(op=='/' || op=='*') return 4;
	if(op=='^') return 5;
	if(op=='[' || op=='{' ||  op=='(') return 0;
	if(op=='~') return -1;
	return 8;
}

stack* stack_initialize(int size)
{
//TODO
    stack *p = (stack *)malloc(sizeof(stack));
    p->arr = (int *)malloc(size*sizeof(int));
	p->top = -1;
    return p;
}

void stack_push(stack *ptr_stack, int key) 
{
//TODO
    (ptr_stack->top)++;
	(ptr_stack->arr)[(ptr_stack->top)] = key; 
}

void stack_pop(stack *ptr_stack)
{
//TODO
	(ptr_stack->top)--;
}

int stack_is_empty(stack *ptr_stack)
{
//TODO
    if(ptr_stack->top==-1) return 0;
    else return 1;
}

int stack_peek(stack *ptr_stack) 
{
//TODO
    return((ptr_stack->arr)[(ptr_stack->top)]);
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
    stack *s = stack_initialize(strlen(source_infix));
	char op;
	int i=0,j=0;
	stack_push(s,'~');

	while(source_infix[i]!='\0')
	{
		op = source_infix[i];

		while(input_prec(op)<stack_prec(stack_peek(s)))
		{	 
		
			target_postfix[j] = stack_peek(s);
			stack_pop(s);
            j++;
		}
		
		if(stack_prec(stack_peek(s))!=input_prec(op)) stack_push(s,op);

		else stack_pop(s);

        i++;
    }
	
	while(stack_peek(s)!='~')
	{	
		target_postfix[j]=stack_peek(s);
		stack_pop(s);
		j++;
	}
    stack_destroy(s);
    target_postfix[j] ='\0';
	
}
