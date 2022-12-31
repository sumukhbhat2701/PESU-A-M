//Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct dnode{
  int info;
  struct dnode *left,*right;
  }DNODE;
  
DNODE* frontins(DNODE*, int);
void display(DNODE*);
DNODE* endins(DNODE*, int);
DNODE* frontdel(DNODE*);
DNODE* enddel(DNODE*);
DNODE* succins(DNODE*,int, int);
DNODE* search_del(DNODE *, int);
DNODE* order_ins(DNODE *, int);

void main()
{
  DNODE *dlist;
  int x,s,choice;
  dlist = NULL;
  while(1)
  {
  printf("  Enter 1-> Front Insertion\n\t\n\t2->End Insertion\n\t3-> Display\n\t");
  printf("4-> Front Deletion\n\t\n\t5->End Deletion\n\t6->Successor Node Info\n");
  printf("7-> Search_delete\t\n8->Ordered Insertion\n");
  scanf("%d",&choice);
  switch(choice)
  {
	case 1: {printf("Enter the value of x");
             scanf("%d",&x); 
			 dlist=frontins(dlist,x);
	        } break;
	case 2: {printf("Enter the value of x");
             scanf("%d",&x); 
			 dlist=endins(dlist,x);
	        } break;		
	case 3: {printf("The list contains...");
             display(dlist);
	        }break;
	case 4: {
			 dlist=frontdel(dlist);
	        } break;
	case 5: {
			dlist=enddel(dlist);
	        } break;
    case 6: {printf("Enter the value of Successor Node Information");
             scanf("%d",&s); 
			 printf("Enter the value of x");
             scanf("%d",&x); 
			 dlist=succins(dlist,s,x);
	        } break;			
	case 7: { 
			 printf("Enter the value of node to be deleted ");
             scanf("%d",&x); 
			 dlist=search_del(dlist,x);
	        } break;		
	case 8: {
			 printf("Enter the value of x");
             scanf("%d",&x); 
			 dlist=order_ins(dlist,x);
	        } break;		
			
	default: exit(0);
   }
  }		
 }
  		

DNODE* frontins(DNODE *dl1, int x)
{   DNODE *new;

    new =(DNODE *)(malloc(sizeof(DNODE)));
	new->info = x;
	new->left=NULL;
	new->right=NULL;
	
  if(dl1 == NULL) dl1=new;
  else {
	    new->right = dl1;
		dl1->left = new;
		dl1=new;
	   }
	   return dl1;
}

void display(DNODE *dl1)
{
  DNODE *temp;
  if(dl1==NULL)printf("List is Empty");
  else{temp=dl1;
	   while(temp!=NULL)
	   {
		   printf("\t%d",temp->info);
	       temp=temp->right;
	   }
   }
}

DNODE* endins(DNODE *dl1, int x)
{   DNODE *new,*temp;

    new =(DNODE *)(malloc(sizeof(DNODE)));
	new->info = x;
	new->left=NULL;
	new->right=NULL;
	
  if(dl1 == NULL) dl1=new;
  else { temp=dl1;
         while(temp->right!=NULL)
			 temp=temp->right;
		 
		 temp->right=new;
		 new->left= temp;
	   }
	   return dl1;
}

DNODE* frontdel(DNODE* dl1)
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
		      printf("the deleted element is  %d ", temp->info);
		      free(temp);
		   }
	    }
	return dl1;
}

DNODE* enddel(DNODE *dl1)
{   DNODE *new,*temp;

  if(dl1 == NULL) printf("Empty List");
  else if(dl1->right==NULL){temp=dl1;
							dl1=NULL;
							free(temp);
                           }
  else { temp=dl1;
         while(temp->right!=NULL)
			 temp=temp->right;
		 
		 (temp->left)->right = NULL;
		 free(temp);
		 }
	   return dl1;
}

DNODE* succins(DNODE *dl1, int succ, int x)
{
  DNODE *temp,*new;
  
    new =(DNODE *)(malloc(sizeof(DNODE)));
	new->info = x;
	new->left=NULL;
	new->right=NULL;
		
	if(dl1==NULL) dl1 = new;
	//front insertion
	else if(dl1->info==succ)
	{
		new->right=dl1;
		dl1->left=new;
		dl1=new; 
	}
	else {
		  temp=dl1;
	      while(temp->right!=NULL && temp->info!=succ)
			   temp=temp->right;
		  if(temp->info==succ)
		  {
		  new->right=temp;
		  new->left = temp->left;
		  temp->left = new;
		  (new->left)->right=new;
		  } 
          else printf("Invalid Successor node's information");
	}
	return dl1;
}

DNODE* search_del(DNODE *dl1,int x)
{  DNODE *temp;
  if(dl1==NULL) printf(" List is Empty..");
  // to delete a node if there is only one node...
  else if (dl1->right == NULL && dl1->left == NULL)
  {
	  temp=dl1;
	  dl1=NULL;
	  free(temp);
  }
  else {  temp=dl1;
	if(dl1->info==x){
						dl1=dl1->right;
						dl1->left=NULL;
						free(temp);
					 }
	else {
		  while(temp->right != NULL && temp->info != x)
			temp=temp->right;
		
		  if(temp->info==x && temp->right!=NULL)
		       {
				(temp->left)->right = temp->right;
		        (temp->right)->left = temp->left;
		        free(temp);
			   }
		        else if(temp->info==x && temp->right==NULL)
					{
					  (temp->left)->right = NULL;
				      free(temp);
				    }
	               else printf("Invalid Data");					
	     }  
    }	
  return dl1;
}

DNODE* order_ins(DNODE * dl1, int x)
{
	DNODE *temp,*new;
  
    new =(DNODE *)(malloc(sizeof(DNODE)));
	new->info = x;
	new->left=NULL;
	new->right=NULL;
		
	if(dl1==NULL) dl1 = new;
	else {
		if(x < dl1->info)
		{   new->right = dl1;
			dl1->left = new;
			dl1=new;
	    }
		else {
			  temp=dl1;
			  while(x > temp->info && temp->right!=NULL)
			  temp=temp->right;
		      
			  if(x < temp->info)
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