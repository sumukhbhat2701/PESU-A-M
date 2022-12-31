#include <stdio.h>
#include <stdlib.h>

struct tnode{
	char data;
	struct tnode *left,*right;
	};

void preorder(struct tnode*);
void inorder(struct tnode*);
void postorder(struct tnode*);

struct tnode* create_exptree(char *);
int isoper(char);

void push(struct tnode **, int *, struct tnode *);
struct tnode* pop(struct tnode**,int *);

int evaluate(struct tnode*);

void main()
{
 struct tnode *root;
 char exp[100];
 
 root=NULL;
 
  printf("\nEnter the postfix expression ...");
  scanf("%s",&exp);
  
  root=create_exptree(exp);
  
//   printf("\nThe preorder form of the expression is..\t");
//   preorder(root);
//   printf("\nThe inorder form of the expression is..\t");
//   inorder(root);
//   printf("\nThe postorder form of the expression is..\t");
//   postorder(root);
  
  
  int result = evaluate(root);
  printf("The evaluation of the expression is ...\t%d",result);
}


void preorder(struct tnode *t)
{
  if(t!=NULL)
  {printf("%c",t->data);
   preorder(t->left);
   preorder(t->right);
  }
}

void inorder(struct tnode *t)
{
  if(t!=NULL)
  {
   inorder(t->left);
    printf("%c",t->data);
   inorder(t->right);
  }
}

void postorder(struct tnode *t)
{
  if(t!=NULL)
  {
   postorder(t->left);
   postorder(t->right);
   printf("%c",t->data);
  }
}

struct tnode* create_exptree(char *exp)
{
	char ch;
	struct tnode *stk[100];
	int top=-1;
	int i=0;
	
	struct tnode *temp;
	
	while(exp[i]!='\0')
	{
      ch=exp[i];
      temp=(struct tnode *)(malloc(sizeof(struct tnode)));	  
	  temp->left=temp->right=NULL;
	  temp->data = ch;
		//same logic for evalpost.c i.e if char==operator -> pop the 2 elements of stack, attach it to the character(r=op1 opearte op2 in case of evalpost.c) and push the resultant
		//else just push
		//finally 1 element left in the stack is the final answer
	  if(isoper(ch))	
	  {
		temp->right=pop(stk,&top);
		temp->left=pop(stk,&top);
		push(stk,&top,temp);
	  }	
     else 	push(stk,&top,temp); 
            i++;	 
	}
	return(pop(stk,&top));
}

int evaluate(struct tnode *t)
{
	int x;
	switch(t->data)
	{
	case '+': return(evaluate(t->left)+evaluate(t->right));
	case '-': return(evaluate(t->left)-evaluate(t->right));
	case '*': return(evaluate(t->left)*evaluate(t->right));
	case '/': return(evaluate(t->left)/evaluate(t->right));
	default:return ((t->data) - '0');
	}
	
}

void push(struct tnode **s,int *t, struct tnode *temp)
{
	++(*t);
    s[*t]=temp;
}

struct tnode* pop(struct tnode **s,int *t)
{
	struct tnode *temp;
	temp=s[*t];
	(*t)--;
	return temp;
}

int isoper(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/': return 1;
		default : return 0;
	}
}