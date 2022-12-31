//Priority Queue Implementation using Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct dnode{
  int info;int pty;
  struct dnode *left,*right;
  }DNODE;
  

void pdisplay(DNODE*);
DNODE* premove(DNODE*);
DNODE* pinsert(DNODE *,int,int);

void main()
{
  DNODE *dlist;
  int x,s,choice,pty;
  dlist = NULL;
  while(1)
  {
  printf("Enter 1-> Insert\n\t 2-> Remove\n\t 3-> Display\n\t 4->exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
	case 1: {printf("Enter the value of x");
             scanf("%d",&x); 
			 printf("Enter the Priority ");
             scanf("%d",&pty);
			 dlist=pinsert(dlist,x,pty);
	        } break;
	case 2: {
			 dlist=premove(dlist);
	        } break;
	case 3: {printf("The Priority Queue contains...");
             pdisplay(dlist);
	        }break;
	default: exit(0);
   }
  }		
 }
  		
void pdisplay(DNODE *dl1)
{
  DNODE *temp;
  if(dl1==NULL)printf("List is Empty\n");
  else{temp=dl1;
	   while(temp!=NULL)
	   {
		   printf("\nData :\t%d",temp->info);
		   printf("Priority :\t%d",temp->pty);
	       temp=temp->right;
	   }
   }
}

DNODE* premove(DNODE* dl1)
{DNODE *temp;
  	if(dl1 == NULL) printf("Empty List..");
	else {
		   temp=dl1;
		   if(dl1->right==NULL)
		   { dl1=NULL;
	         free(temp);
	       }
		   else {
			  dl1=dl1->right;
		      dl1->left=NULL;
		      printf("The deleted element is  %d with Priority %d", temp->info,temp->pty);
		      free(temp);
		   }
	    }
	return dl1;
}


DNODE* pinsert(DNODE * dl1, int x,int pty)
{
	DNODE *temp,*new;
  
    new =(DNODE *)(malloc(sizeof(DNODE)));
	new->info = x;
	new->pty = pty;
	new->left = NULL;
	new->right = NULL;
		
	if(dl1==NULL) dl1 = new;
	else {
		if(pty < dl1->pty) // check for pty field instead of data
		{   new->right = dl1;
			dl1->left = new;
			dl1=new;
	    }
		else {
			  temp=dl1;
			  while(pty >= temp->pty && temp->right!=NULL)
			  temp=temp->right;
		      
			  if(pty < temp->pty)
			  {
				new->right=temp;
				new->left = temp->left;
				temp->left = new;
				(new->left)->right=new;  
			  }
			  else 
			  {
				  new->left=temp;
				  temp->right=new;
			  }  
		}
		
	}
	return dl1;
}