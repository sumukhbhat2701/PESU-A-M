#include <stdio.h>
#include <stdlib.h>

void push(char,char*,int*);
char pop(char*,int*);
char peek(char*,int*);
void convert_postfix(char *, char *);
int input_prec(char);
int stack_prec(char);
void reverse(char *);

void main()
{
	char prefix[20];
	char infix[20];
	
	
	printf("Enter a valid infix expression");
	scanf("%s",infix);
	// reverse the given string
	reverse(infix);

	convert_postfix(infix,prefix);
	
	//reverse the postfix expression
	reverse(prefix);
	printf("The PREFIX expression is %s\t",prefix);
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
	
	if(stack_prec(peek(stk,&top))!=input_prec(sym))
		push(sym,stk,&top);
	else pop(stk,&top);
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
	case '-': return 2;
	case '*':
	case '/': return 4;
	case '^': return 5;
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
	case '-': return 1;
	case '*':
	case '/': return 3;
	case '^': return 6;
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

void reverse(char *prefix)
{char x;
 int i,t;
    char s1[20];
	int t1=-1;
	
	for(i=0;prefix[i]!='\0';i++);
	t=i;
		
	for(i=0;i<t;i++)
	{   x=prefix[i]; 
	    if(x=='(') x=')';           // here before pushing to stack
		else if (x==')') x='(';    // reverse the parenthesis '(' to ')'  and
      	push(x, s1, &t1);    	  //  ')' to '('.         
	}
	
	for(i=0;i<t;i++)
	{
	  x=pop(s1,&t1);
	  prefix[i]=x;
	}
}

