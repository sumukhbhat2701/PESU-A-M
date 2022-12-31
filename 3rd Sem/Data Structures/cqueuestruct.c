#include<stdio.h>
#include<stdlib.h> 

//queue using a structure

typedef struct queue
 {
   int *q;
   int f,r;
   int size;
  }QUEUE;
  
  void insert(QUEUE *, int );
  void remove1(QUEUE *);
  void display(QUEUE *);
 /* int iscqfull(QUEUE *);
  int iscqempty(QUEUE *);*/

  void main()
  {
   QUEUE que; 
   int x,ch,k;
   int f,r,size;
   printf("Enter the size\n");
   scanf("%d",&que.size);
   que.q=(int*)malloc(sizeof(int)*que.size);
   que.f=que.r=-1;
  while(1)
  {
    
    printf("\n1.INSERT\n");
    printf("\n2.DELETE\n");
    printf("\n3.DISPLAY");
    
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:{printf("Enter the element..\n");
            scanf("%d",&x);
            insert(&que,x);
            }break;
     case 2:{remove1(&que);
            }break;
     case 3:{display(&que);
            }break;
     case 4:exit(0);
     }
   }
 }

  void insert(QUEUE *que, int x)
   {  printf("entered queue");
     if((que->r+1) % que->size == que->f )
      {
        printf("Queue full\n");
      }
      if(que->f==que->r==-1) que->f++;
        
       que->r=(que->r+1) % que->size; //increment rear pointer  r=(r+1)%size;

       que->q[que->r]=x;
      printf("%d", que->q[que->r]);
   }
   

  void remove1(QUEUE *que)
   {
     int x;
     if(que->f == -1) //check for queue empty
        printf("Queue empty\n");
      if(que->f==que->r)que->f=que->r=-1;
      else {  x=que->q[que->f];    //get element pointed by f
              que->f=(que->f+1) % que->size;
           }
        printf("The Deleted element is %d", x);
     }


 void display(QUEUE *que)
  {
    int i;
    if(que->f==-1)
     printf("Queue empty\n");
     else
     {  i=que->f;
        while(i!=que->r)
       { printf("%d ",que->q[i]);
         i=(i+1)%que->size;
       }
       printf("%d ",que->q[i]);
     }
   }















  
