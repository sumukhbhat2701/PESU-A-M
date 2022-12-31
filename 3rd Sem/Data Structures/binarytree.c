	#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node *left,*right;
}TREE;

TREE* lexins(TREE *,int);
void preorder(TREE*);
void inorder(TREE*);
void postorder(TREE*);
int minval(TREE*);
int maxval(TREE*);
void noofnodes(TREE*);
void noofleafnodes(TREE*);

int height(struct node *t)
		{
			int l,r;
			if(t==NULL) //empty tree
				return -1;
				//one node tree
			if((t->left==NULL)&&(t->right==NULL))
				return 0;
			l=height(t->left);//height of left subtree
			r=height(t->right);//height of right subtree
			if(l>r)
				return 1+l;
			else
				return 1+r;
		}


TREE* deletenode(TREE*,int);

int count=0,leafcount=0;

int main()
{
TREE *root;
int choice,x;
root=NULL;

while(1)
{
	printf("\n\t1->Insertion \n\t2->Preorder Traversal\n");
	printf("\t3->Inorder Traversal\n\t4->Postorder Traversal\n");
	printf("\t5->Min value\n\t6->Max Value\n");
	printf("\t7->No of Nodes in the tree\n\t8->No of Leaf Nodes in the tree\n");
	printf("\t9->Deletion of a node from the tree\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1: {
		     printf("Enter the value..");
			 scanf("%d",&x);
			 root = lexins(root,x);
			}break;
	case 2: {
		     preorder(root);
			}break;
	case 3:{
		     inorder(root);
			}break;
	case 4:{
		     postorder(root);
			}break;
	case 5: {x=minval(root);
			 printf("\nMin val is %d",x);
			}break;
	case 6: {x=maxval(root);
			 printf("\nMax val is %d",x);
			}break;
	case 7: {noofnodes(root);
	        printf("\nNo of nodes in the tree are..%d",count);
			}break;
	case 8: { noofleafnodes(root);
	        printf("\nNo of leaf nodes in the tree are..%d",leafcount);
			}break;
	case 9: { printf("\nEnter the information of the node to be deleted from tree ");
			  scanf("%d",&x);
	          root=deletenode(root,x);
			}break;
	default: printf("%d",height(root));
	exit(0);		
	}
}

}

TREE* lexins(TREE *root,int x)
{
  	TREE *newnode,*temp;
	int flag=1;
	
	newnode=(TREE *)(malloc(sizeof(TREE)));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->info=x;
	
	if(root==NULL)root=newnode;
	else {temp=root;
	     while(flag)
		 {
		if(x < temp->info)
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

void preorder(TREE* root)
{
	if(root!=NULL)
	{
	printf("\t%d",root->info);
    preorder(root->left);
	preorder(root->right);
   }
}

void inorder(TREE* root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	printf("\t%d",root->info);
	inorder(root->right);
   }
}

void postorder(TREE* root)
{
	if(root!=NULL)
	{
	postorder(root->left);
	postorder(root->right);
	printf("\t%d",root->info);
	}
}
int minval(TREE* root)
{TREE *temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
		return(temp->info);
}

int maxval(TREE* root)
{TREE *temp=root;
	while(temp->right!=NULL)
		temp=temp->right;
		return(temp->info);
}

void noofnodes(TREE* root)
{
	if(root!=NULL)
	{
	noofnodes(root->left);
	noofnodes(root->right);
	count++;
	}
}

void noofleafnodes(TREE* root)
{
	if(root!=NULL)
	{
	noofleafnodes(root->left);
	noofleafnodes(root->right);
	if(root->left==NULL && root->right ==NULL)leafcount++;
	}
}

TREE* deletenode(TREE *root, int key)
{
	TREE *temp,*q,*parent,*insucc;
	q=NULL;
	temp=root;
	parent=NULL;
	
	// search for a given information in the tree
		while(temp!=NULL && temp->info!=key)
		{
			parent=temp;
			if(key<temp->info)
				temp=temp->left;
			else temp=temp->right;
		}
		
	if (temp==NULL)	printf(" Unsuccessful search...Key not found....");
    else if(temp->left==NULL)q=temp->right; //single child case
	else if(temp->right==NULL)q=temp->left; //single child case
	else { //two child nodes
	   // find the inorder successor of the temp node
		insucc=temp->right;
		while(insucc->left!=NULL)
			insucc=insucc->left;
		
		insucc->left = temp->left;
		           q = temp->right;
		}
		
		// attach q
		
		if(parent==NULL)// delete the root node
		    root = q;
		else if(temp=parent->left)parent->left =q;
		else if(temp=parent->right)parent->right=q;
		   free(temp);
		   count--;
		   return root;
}
		
		
		

		
			












