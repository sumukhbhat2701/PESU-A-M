#include <stdio.h>
#include <stdlib.h>

struct pqueue{
	int data;
	int pty;
};

void pqinsert(int, int, struct pqueue *,int *);
struct pqueue pqdelete(struct pqueue*,int *);
void qdisplay(struct pqueue*,int );


int main()
{
   struct pqueue pq[100],temp;
   int ch,pty,x;
   int count=0;
   
	while(1)
	{   qdisplay(pq,count);
		printf("Enter\n\t 1->Insert\n\t2->Remove\n\t3->Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:{
				printf("Enter the Priority..");
				scanf("%d",&pty);
				printf("Enter the Data..");
				scanf("%d",&x);
				pqinsert(pty,x,pq,&count);
				}break;
		case 2:	{
		          temp=pqdelete(pq,&count);
				  if(temp.data >0)
					printf("The removed element for the priority queue is %d\t%d",temp.pty,temp.pty);
				}break;
		default: exit(0);
		}
	}
}

void pqinsert(int pty, int x, struct pqueue *pq,int *count)
{  
  int j;
  struct pqueue key;
  key.data = x;
  key.pty= pty;
  j=*count-1;
  
  while((j>=0)&&(pq[j].pty > key.pty))
  {
     pq[j+1]=pq[j];
	 j--;
  }
  pq[j+1] = key;
  (*count)++;	
}

struct pqueue pqdelete(struct pqueue *pq,int *count)
{int i;
	struct pqueue temp;
	if(*count==0){
		temp.pty=-1;
		temp.data=-1;
	}
	else {
		temp=pq[0];
		for(i=1;i<*count-1;i++)
			pq[i-1]=pq[i];
		(*count)--;
	}
}

void qdisplay(struct pqueue *pq,int count)
{
	int i;
	if(count==0)printf("Empty Queue");
	else {
		for(i=0;i<count;i++)
		{	printf("\nData = %d ",pq[i].data);
			printf("Priority = %d\n ",pq[i].pty);
        }
	}
}