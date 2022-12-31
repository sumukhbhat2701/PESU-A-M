#include<stdio.h>
#include<stdlib.h>

void pqinsert(int, int);
void pqdelete();
void display();
void adjust();


// functions for a priority queue 
//represented as a heap

struct heap
{
  int data;
  int pty;
 };

struct heap h[10];
int count =0;

void main()
{  
   int x,p,ch;
 
 while(1)
  {
    printf("Enter \n1.INSERT\n");
    printf("\t\n2. DELETE\n");
    printf("\t\n3. DISPLAY");
    
    scanf("%d",&ch);

    switch(ch)
    {
     case 1:{printf("Enter the element..\n");
            scanf("%d",&x);
            printf("Enter the Priority..\n");
            scanf("%d",&p);
            pqinsert(x, p);
            } break;
     case 2:{ pqdelete();} break;
     case 3: {display();} break;
    case 4:exit(0);
     }
   }
 }

//function to insert an element with a given priority 
//into a priority queue represented as a heap

 void pqinsert( int x, int p)
 { int i,j;
  struct heap temp;
  temp.data=x;
  temp.pty=p;

  h[count]=temp;     //initial position of the element
  count++;

  //HEAPIFY/top bottom(move the parent down) only wrt to inserted element as key i.e we need not use a for loop!

  i=count-1;
  j=(i-1)/2;
  
  //as long as the pty of the element being inserted
  //is lower than the pty of the parent
  //move the parent down
  
while((i>0) &&(temp.pty < h[j].pty))
  {
    h[i]=h[j];
    i=j;
    j=(i-1)/2;
  }
  h[i]=temp;
}
 

 // function to delete an element
//from a priority queue represented as a heap
 
void pqdelete()
 {
    struct heap temp;
    temp=h[0];
    h[0]=h[count-1];
    (count)--;
    int i,j;
    struct heap key;

    //bottom up approach/adjust(move the child up), but no need to for loop. Just once with key as root node

    key=h[0];
    j=0;
    i=j*2+1;// get the left child

    while(i<=count-1)//as long as a left child exists
    {
    if((i+1)<=count-1)//right child exists
    {
    if(h[i+1].pty<h[i].pty)
        i++;//get the index of the smallest child
    }
    if(key.pty > h[i].pty)
    {
      h[j]=h[i]; //move the child up
      j=i;
      i=2*j+1;
    }
    else
      break;
    }
  h[j]=key;  
 }

   
 //function to re create a heap after deleting the element
 //from a priority queue represented as a heap



void display()
{
 int i=0;
  while(i<=count-1)
  {
   printf("\t %d | %d ",h[i].data, h[i].pty);
   i++;
  }
}










   

     
  
