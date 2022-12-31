#include <stdio.h>
#include <stdlib.h>

void push(char,char*,int*);
char pop(char*,int*);
char peek(char*,int*);
void convert_postfix(char *, char *);
int input_prec(char);
int stack_prec(char);


void main()
{
	char postfix[20];
	char infix[20];
	
	printf("Enter a valid infix expression");
	scanf("%s",infix);
	convert_postfix(infix,postfix);
	printf("The POSTFIX expression is %s\t",postfix);
}
	
void convert_postfix(char *infix,char *postfix)
{   char stk[20];
	char sym;
	int i=0,j=0;
	int top = -1;
	push('#',stk,&top);

	while(infix[i]!='\0')
	{
	sym=infix[i];
	
	while(stack_prec(peek(stk,&top))>input_prec(sym))
	     postfix[j++]=pop(stk,&top);
	//when it comes out of obove loop, either stack_prec <[!= i.e everything except ( and )] or =[only when input is ) and stack_top is ( ] input_prec
	if(stack_prec(peek(stk,&top))!=input_prec(sym))
		push(sym,stk,&top);
	else pop(stk,&top);  //don't store as it in postfix array as they will ( and ) which wont be there in a postfix expression
	i++;
    }
	
	while(peek(stk,&top)!='#')
		postfix[j++]=pop(stk,&top);
    postfix[j]='\0';
	
}

int input_prec(char ch)
{
	 switch(ch)
	 {
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 3;
	case '^': return 6;
	case '(': return 9;
	case ')': return 0;
	default : return 7;
		 }
}

int stack_prec(char ch)
{
	 switch(ch)
	 {
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 4;
	case '^': return 5;
	case '(': return 0;
	case '#': return -1;
	default : return 8;
	}
}

void push(char ch,char *s,int *t)
    {    
	 (*t)++;
	 s[*t]=ch; 
	 }

char pop(char *s,int *t)
{   char x;
      x= s[*t];
	  (*t)--;
	return x;
}

char peek(char *s,int *t)
{   char x;
      x= s[*t];
	 return x;
}