  #include<stdio.h>
  #include<stdlib.h>
  
  // function prototypes
   void display(int *,int);
   void heapify(int *, int);
   int maxremove(int*, int*);
   void adjust(int *,int);
    
 void main()
 {
  int count,num,i;
  int h[20];

  printf("Enter the no of elements");
  scanf("%d", &count);

  printf("Enter the elements..");
  for(i=0;i<count;i++)
    scanf("%d", &h[i]);
  
  printf("\n\tBefore heap is created.....");
  display(h,count);
  
  heapify(h,count);
  
  printf("\n\tAfter heap is created.....");
  display(h,count);
  
  num=maxremove(h,&count);
  printf("The maximum element removed..%d\n",num);
  
  printf("New Heap after removal of the max element is");
  display(h,count);
  
 }

 void heapify(int *h, int count) //top down : Store key=h[child](only once and not in every while loop!) and compare it with its parent. If parent is lower, push the parent value lower(and dont push the child value up). Once the loop breaks assign the h[child] value to the largest parent
 {
	int i,j,k,key;
    // every element in the tree	
	for(k=1;k<count;k++)
	{ i=k;
	  key=h[i];
	  j=(i-1)/2; //i = 2j+1 for left child and for right child, int(2j+1) is approximately equal to 2j+2
	  
	  while((i>0)&&(h[j]<key))   //compare parent with key, not h[i]!!!
	  {
		h[i]=h[j];  //push smaller number down(not swap entirely).
		i=j;
		j=(i-1)/2;
	  }
    //loop is broken when i=0(parent where j=i=0 bcz j=int(0-1/2)=0) or j such that h[j]>key
	  h[i]=key; //largest number is recorded in proper position

	}
 }

void display(int *h,int count)
{
  int i;
  for (i=0;i<count;i++)
   printf("\t%d",h[i]);	  
}

int maxremove(int *h, int *count)
{
	// fill the code
  int max = h[0];
  h[0] = h[*count - 1]; //assign max element to last element of heap
  (*count)--;
  adjust(h,*count);  //use bottom up as it is better than heapify/top down
  return max;  //store these return values for all the elements in a new array or blank space in the same array and it is "heap sort"


}

void adjust(int *h,int count) //bottom up : better than heapify as it just compares only where required
{
	
	// fill the code
  //n is the index of the last element
	int k,i,j,key;

	for(k=(n-1)/2; k>=0;k--)
	{
		i=k;
		key=h[i];
		
		j=2*i+1;//get the index of left child
		
		while(j<=n)//until left child exists
		{
			if((j+1)<=n)//check if right chikd exists
			{
				if(h[j+1]>h[j])
					j++; //get the index of largest child
			}
			if(key<h[j])
			{
				h[i]=h[j];//move child up
				i=j;
				j=2*i+1; //get the left child
			}
			else
			 break;	
		}
     h[i]=key;//insert the key
	}	
	
}

//For heap sort: Delete the max element and store somewhere and after each deletion call adjust(better)/heapify. Repeat until heap is empty


//NOTE: Use top down if at every step of insertion there needs to be a conversion.(no for loop just once with the inserted key as h[i])(eg; priority queue insertion)
//If conversion is final after insertion all the steps use bottom top approach(eg: priority queue deletion)
//However we can interchange
