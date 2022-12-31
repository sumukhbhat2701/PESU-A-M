//Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct dnode{
  int info;
  struct dnode *left,*right;
  }DNODE;
  
DNODE* cfrontins(DNODE*, int);
void cdisplay(DNODE*);
DNODE* cendins(DNODE*, int);
DNODE* cfrontdel(DNODE*);
DNODE* cenddel(DNODE*);
/*DNODE* succins(DNODE*,int, int);
DNODE* search_del(DNODE *, int);*/

void main()
{
  DNODE *clist;
  int x,s,choice;
  clist = NULL;
  while(1)
  {
  printf("  Enter 1-> Front Insertion\n\t\n\t2->End Insertion\n\t3-> Display\n\t");
  printf("4-> Front Deletion\n\t\n\t5->End Deletion\n\t6->Successor Node Info\n");
  printf("7-> Search_delete\t\n");
  scanf("%d",&choice);
  switch(choice)
  {
	case 1: {printf("Enter the value of x");
             scanf("%d",&x); 
			 clist=cfrontins(clist,x);
	        } break;
	case 2: {printf("Enter the value of x");
             scanf("%d",&x); 
			 clist=cendins(clist,x);
	        } break;	
	case 3: {printf("The list contains...");
             cdisplay(clist);
	        }break;
	case 4: {
			 clist=cfrontdel(clist);
	        } break;
	case 5: {
			clist=cenddel(clist);
	        } break;
    case 6: {
			 printf("Enter the value of x");
             scanf("%d",&x); 
			 clist=cordins(clist,x);
	        } break;			
	/*case 7: { 
			 printf("Enter the value of node to be deleted ");
             scanf("%d",&x); 
			 dlist=search_del(dlist,x);
	        } break;	*/	
	default: exit(0);
   }
  }		
 }
  		
DNODE* cfrontins(DNODE *cl1, int x)
{   DNODE *new,*temp;

    new =(DNODE *)(malloc(sizeof(DNODE)));
	new->info = x;
	new->left=NULL;
	new->right=NULL;
	
  if(cl1 == NULL) { cl1=new;
					cl1->left=cl1;
					cl1->right=cl1;
				  }
  else {temp=cl1;
        new->right = cl1;
		new->left  = cl1->left;
	    cl1->left  = new;
		new->left->right=new;
		cl1=new;
		}
	   return cl1;
}



void cdisplay(DNODE *cl1)
{
  DNODE *temp;
  if(cl1==NULL)printf("List is Empty");
  else{temp=cl1;
       
	   while(temp->right!=cl1)
	   {
		   printf("\t%d",temp->info);
	       temp=temp->right;
	   }
	   printf("\t%d",temp->info);
   }
}

DNODE* cendins(DNODE *cl1, int x)
{   DNODE *new,*temp;

    new =(DNODE *)(malloc(sizeof(DNODE)));
	new->info = x;
	new->left=NULL;
	new->right=NULL;
	
  if(cl1 == NULL) { cl1=new;
					cl1->left=cl1;
					cl1->right=cl1;
				  }
  else {temp=cl1;
        new->right = cl1;
		new->left  = cl1->left;
	    cl1->left  = new;
		new->left->right=new;
		}
	   return cl1;
}


DNODE* cfrontdel(DNODE* cl1)
{DNODE *temp;
  	if(cl1 == NULL) printf("Empty List..");
	else {
		   temp=cl1;  
		   if(cl1->right==cl1 && cl1->left==cl1)
		   { cl1=NULL;
	        }
		   else {
				cl1=cl1->right;
				cl1->left=temp->left;
				(cl1->left)->right=cl1;
			 	}
		      printf("the deleted element is  %d ", temp->info);
		      free(temp);
		   }
	    
	return cl1;
}

DNODE* cenddel(DNODE* cl1)
{DNODE *temp;
  	if(cl1 == NULL) printf("Empty List..");
	else {
		   temp=cl1;  
		   if(cl1->right==cl1 && cl1->left==cl1)
		   { cl1=NULL;
	        }
		   else {
				temp=cl1->left;
				cl1->left=temp->left;
				(cl1->left)->right=cl1;
			 	}
		      printf("the deleted element is  %d ", temp->info);
		      free(temp);
		   }
	    
	return cl1;
}

