//Local Variables
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int info;
  struct node *next;
  }NODE;
  
NODE* frontins(NODE*, int);
void display(NODE*);

void main()
{
  NODE *list;
  int x,pos,choice;
  list = NULL;
  while(1)
  {
  printf("  Enter 1-> Front Insertion\n\t2-> Display\n\t");
  
  scanf("%d",&choice);
  switch(choice)
  {
	case 1: {printf("Enter the value of x");
             scanf("%d",&x); 
			 list=frontins(list,x);
	        } break;
	
	case 2: {printf("The list contains...");
             display(list);
	        }break;
	
	default: exit(0);
   }
  }		
 }
  		

NODE* frontins(NODE *l1, int x)
{   NODE *new;
    new =(NODE *)(malloc(sizeof(NODE)));
	new->info = x;
	new->next=NULL;
	
  if(l1 == NULL) l1=new;
  else {
	    new->next = l1;
		l1=new;
	   }
	   return l1;
}

void display(NODE *l1)
{
  NODE *temp;
  if(l1==NULL)printf("List is Empty");
  else{temp=l1;
	   while(temp!=NULL)
	   {
		   printf("\t%d",temp->info);
	       temp=temp->next;
	   }
   }
}
/*
void endins(int x)
{
	NODE *temp;
	create(x);
	if(list==NULL) list = new;
	else 
	   {temp=list;
	    while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
	   }
}

int frontdel()
 { NODE *temp;
  int x;
  if(list == NULL) printf("Empty List");
  else {
	     temp=list;
		 list=list->next;
		 x=temp->info;
		 free(temp);
		 return x;
       }
}

int enddel()
{ NODE *temp,*prev;
  int x;
  if(list == NULL) printf("Empty List");
  else if(list->next==NULL)
  {temp=list;
   x=temp->info;
   list=NULL;
   return x;     
  }
  else {
	  temp=list;
	  while(temp->next!=NULL)
	  {  prev=temp;
		 temp=temp->next;
	  }
	  x=temp->info;
	  prev->next=temp->next;
	  free(temp);
	  return x;
	  }
}

void posins(int pos, int x)
{
  NODE *temp,*prev;
  int i=1;
	create(x);
	//position is ignored only in the beginning.
	if(list==NULL) list = new;
	else if(pos==1)
	{
      new->next=list;
	  list=new;
	}
	else {temp=list;
	      while(temp->next!=NULL && i<pos)
		  {
			  prev=temp;
			  temp=temp->next;
			  i++;
		  }
		  if(i==pos)
		  {
		  new->next=prev->next;
		  prev->next=new;
		  } 
          else if (++i==pos)	  
		     {
			  temp->next=new;
			  }
		     else printf("Invalid Position");
	}
}

int posdel(int pos)
{
  NODE *temp,*prev;
  int i=1,x=-1;
	if(list==NULL) printf("Empty List..");
	else { temp=list;
	       if(pos==1)
		   {
			 list=list->next;
			 x=temp->info;
			 free(temp);
			}
			else {
		    while(temp->next!=NULL && i<pos)
		      {
			  prev=temp;
			  temp=temp->next;
			  i++;
		      }
		     if(i==pos)
		     {
		     prev->next=temp->next;
			 x=temp->info;
			 free(temp);
		     } 
             else printf("Invalid Position");
			}
	   }
	
    return x;
  }


*/
