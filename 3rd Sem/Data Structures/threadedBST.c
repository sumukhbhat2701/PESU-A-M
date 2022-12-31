#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
  bool lthread;
  bool rthread;
};

// function prototypes
struct tnode* insert(struct tnode*,int);
void inorder(struct tnode*);
struct tnode* inordersuccessor(struct tnode *);


void main()
{
  struct tnode *root;
  int ch,num;
  
  root=NULL;
  
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2..Inorder Traversal.");
      printf("\n3.exit");
	  
      scanf("%d",&ch);
       switch(ch)
       {
         case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 root=insert(root,num);
                 break;
         
         case 2:printf("Inorder traversal..\n");
               inorder(root);
               break;

         case 3:exit(0);
       }
    }
  }    

struct tnode* insert(struct tnode *t, int x)
{
	struct tnode* curr,*temp;
	curr=t;
	
	temp=(struct tnode*)(malloc(sizeof(struct tnode)));
	temp->data = x;
	temp->lthread = true;
	temp->rthread = true;
	temp->left=NULL;
	temp->right=NULL;
	//search for the position of the node to be inserted
	if(curr==NULL) return temp;
	
	while(curr != NULL) //!!!!
	{
		if(x < curr->data)
		{
		  if(curr->lthread==false)
			  curr=curr->left;
		  else break;	
		}
		else {
			if(curr->rthread==false)
			  curr=curr->right;
		    else break;	
		}
	}
	//Assign the node
	if(x < curr->data)
	{
	  temp->left=curr->left;
	  temp->right=curr;
	  curr->lthread=false;
	  curr->left=temp;
	}
	else 
	{
	  temp->right=curr->right;
	  temp->left=curr;
	  curr->rthread=false;
	  curr->right=temp;
	}
	return t;
}

void inorder(struct tnode *t)
{
  printf(" Inside Inorder...");
  struct tnode *curr;
  if(t==NULL) printf("Empty Tree..");
  else { curr=t;
	  //flag
	  while(curr->lthread==false) //no need to check for NULL
		  curr=curr->left;
	  
	  while(curr !=NULL)    //same as insert condition
	  {
		  printf("\t%d",curr->data);
		  curr=inordersuccessor(curr);
	  }  
     }  
}

struct tnode* inordersuccessor(struct tnode *t)
{
  if(t->rthread== true)
	  return t->right;  // go to the right node
  // else repeat the steps after going to right i.e after going to its right node, goto "flag" marked in inorder() function (repeat the procedure) considering it as root node!!!
  t=t->right;
  while(t->lthread==false)  //no need to check for NULL condition // go to the left most node in the tree.
	  t=t->left;
  return t;
}


//!!!!!
// no checking for curr->left and right == NULL in the entire program!!!!!!
// either threads or curr!=NULL