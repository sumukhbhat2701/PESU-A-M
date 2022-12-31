//Linear Queue or Simple Queue

#include <stdio.h>
#include <stdlib.h>

#define Max 5

int enque(int[],int *,int *,int);
int deque(int[],int*,int*);
void display(int[],int*,int*);


void main()
{ 
	int q[Max];
	int front =-1;int rear =-1;
	int choice,x,k;

	printf("Enter 1-> Insert\n\t2-> Enque\n\t3-> Display\n");
	
	while(1)
	{	
    scanf("%d",&choice);
	switch(choice)
	{
		case 1:{ printf("Enter the element to insert..");
		         scanf("%d",&x);
				 k=enque(q,&front,&rear,x);
				 if(k>0)printf("Successful Insertion...");
				} break;
		case 2:{ if(front==-1&& rear ==-1)printf("Empty queue");
		         else { k=deque(q,&front,&rear);		
				      printf("Removed element from the queue is..%d",k);
		             }
	        	}break;	
		case 3:{printf("The elements in the queue are ..");
                display(q,&front,&rear);
		       }break;			 
		default: exit(0);
	}
  }
}

int enque(int que[],int *f,int *r,int x)
{
	if(*r==Max-1){
					printf("Queue Full ");
					return -1;
					}
	else {
		   if(*f==-1 && *r== -1)(*f)++;
	   	   (*r)++;
		   que[*r]=x;
	     }
		 return 1;
}

void display(int que[],int *f,int *r)
{   int i;
    if (*f==-1 && *r==-1) printf("Empty Queue...");
	else {   
			for(i=*f;i<=*r;i++)
		     printf("\t%d",que[i]);	
		}
}

int deque(int que[],int *f,int *r)
{ int x;
  if (*f==*r)
            { x=que[*f];
		     *r=-1;*f=-1;
            }
  else  {x=que[*f];
         (*f)++;
        }  
  return x;
}