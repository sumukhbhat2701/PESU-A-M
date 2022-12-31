//Circular Queue 

#include <stdio.h>
#include <stdlib.h>

#define size 5

int cenque(int[],int *,int *,int);
int cdeque(int[],int*,int*);
void cdisplay(int[],int*,int*);


void main()
{ 
	int cq[size];
	int front =-1;int rear =-1;
	int choice,x,k;

	printf("Enter 1-> Enque\n\t2-> Deque\n\t3-> Display\n");
	
	while(1)
	{	
    scanf("%d",&choice);
	switch(choice)
	{
		case 1:{ printf("Enter the element to insert..");
		         scanf("%d",&x);
				 k=cenque(cq,&front,&rear,x);
				 if(k>0)printf("Successful Insertion...\n");
				} break;
		case 2:{ if(front==-1&& rear ==-1)printf("Empty queue");
		         else { k=cdeque(cq,&front,&rear);		
				      printf("Removed element from the queue is..%d\n",k);
		             }
	        	}break;	
		case 3:{ printf("The elements in the queue are ..");
                 cdisplay(cq,&front,&rear);	
		       }break;				 
		default: exit(0);
	}
  }
}

int cenque(int que[],int *f,int *r,int x)
{
	if((((*r)+1)%size)==*f)
					{
					printf("Queue Full ");
					return -1;
					}
	else {
		   if(*f==-1 && *r== -1)(*f)++;
	   	   *r=((*r)+1)%size;
		   que[*r]=x;
	     }
		 return 1;
}

void cdisplay(int que[],int *f,int *r)
{   int i;
    if (*f==-1 && *r==-1) printf("Empty Queue...");
	else {
		i=*f;
		while(i!=*r)
		{  printf("\t%d",que[i]);	
		   i=(i+1)%size;
		}
		printf("\t%d",que[i]);
	}
}

int cdeque(int que[],int *f,int *r)
{ int x;
  if (*f==*r)
            { x=que[*f];
		     *r=-1;*f=-1;
            }
  else  {
		  x=que[*f];
         *f=((*f)+1)%size;
        }  
  return x;
}




