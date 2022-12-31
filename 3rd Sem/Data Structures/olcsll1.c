#include <stdio.h>
#include <stdlib.h>
void frontins(int );
void create(int);
void display();
void endins(int);
int frontdel();
int enddel();
void posins(int, int);
int posdel(int);

typedef struct node{
  int info;
  struct node *next;
  }NODE;
  
NODE *list,*new;

void main()
{int x,pos,choice;
  list = NULL;
  while(1)
  {
  printf("  Enter 1-> Front Insertion\n\t2-> End Insertion\n\t3-> Display\n\t");
  printf("4-> Front Deletion\n\t5-> End Deletion\n\t6->Position Insertion\n\t");
  printf("7-> position Deletion\n\tExit");
  scanf("%d",&choice);
  switch(choice)
  {
	case 1: {printf("Enter the value of x");
             scanf("%d",&x); 
			 frontins(x);
	        } break;
	case 2: {printf("Enter the value of x");
             scanf("%d",&x); 
			 endins(x);
	        } break;	
	case 3: {printf("The list contains...");
             display();
	        }break;
	case 4:{
		    printf("The deleted Element is ..%d ", frontdel());
	       }break;
	case 5:{
		   printf("The deleted Element is ..%d ", enddel());  
		   }break;
	case 6:{
		    printf("Enter the position to be entered");
			scanf("%d",&pos);
			printf("Enter the value");
			scanf("%d", &x);
			posins(pos,x);
	       }break;
	case 7:{
		    printf("Enter the position to be entered");
			scanf("%d",&pos);
			x=posdel(pos);
			if(x==-1)printf("Empty list");
			else printf("the deleted element is %d..",x);
	       }break;
	default: exit(0);
   }
  }		
 }
  		
void create(int x)
{
	new =(NODE *)(malloc(sizeof(NODE)));
	new->info = x;
	new->next=NULL;
}	

void frontins(int x)
{ 
  create(x);
  if(list == NULL) list=new;
  else {
	    new->next = list;
		list=new;
	   }
}

void display()
{
  NODE *temp;
  if(list==NULL)printf("List is Empty");
  else{temp=list;
	   while(temp!=NULL)
	   {
		   printf("\t%d",temp->info);
	       temp=temp->next;
	   }
   }
}

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



