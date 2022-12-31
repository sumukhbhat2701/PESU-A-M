#include <stdio.h>
#include <stdlib.h>

struct tnode{
	int data;
	struct tnode *left,*right;
	};

struct tnode* BSTinsert(struct tnode*,int);
void inorder(struct tnode*);

void push(struct tnode *);
struct tnode* pop();
int isempty();

struct tnode *stk[100];  //stack
int top;

void main()
{
 int num; 
 struct tnode *root;
 
 root=NULL;
 
 while(1)
 {
	 printf("Enter the element..");
	 scanf("%d",&num);
	 if(num==0)
		 break;
	 else root=BSTinsert(root,num);
 }
 
 printf("The inorder traversal of the Tree is ...");
 inorder(root);
}
 
  

void inorder(struct tnode *t)
{
  top=-1;
  while(t!=NULL)
  {
	push(t);
	t=t->left;
  }	  
  
  while(!isempty())  // stck not empty
  {
  t=pop();
  printf("%d",t->data);
  
   if(t->right!=NULL)
   {
	  t=t->right;
	  while(t!=NULL)
		{
		   push(t);
		   t=t->left;
		}
     }
  }	
}

	
struct tnode* BSTinsert(struct tnode *root,int x)
{
	int flag=1;
	
	struct tnode *temp,*newnode;
	
	  newnode=(struct tnode *)(malloc(sizeof(struct tnode)));	  
	  newnode->left=newnode->right=NULL;
	  newnode->data = x;
	
    if(root==NULL)root=newnode;
	else {temp=root;
	     while(flag)
		 {
		if(x < temp->data)
		{if(temp->left==NULL)
		   { temp->left=newnode;
	         flag=0;
		   }
		   else temp=temp->left;
		}  
	   else {
		     if(temp->right==NULL)
		     { temp->right=newnode;
			   flag=0;
			 }
			else temp=temp->right;
	        }
		 }
	}
	return root;	
}


void push(struct tnode *temp)
{
	++top;
    stk[top]=temp;
}

struct tnode* pop()
{
	struct tnode *temp;
	temp=stk[top];
	top--;
	return temp;
}

int isempty()
{
	if(top==-1) return 1; 
	else return 0;
}
