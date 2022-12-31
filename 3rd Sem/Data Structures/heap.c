 #include<stdio.h>
 //implement heap by using bottom up technique
  void bot_heap(int*,int);
  void top_heap(int *, int);
  
  int main()
  {
    int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
   // bot_heap(h,n-1);//pass index of last element
   top_heap(h,n-1);//pass index of the last element 
   printf("After creating heap..\n");
    for(i=0;i<n;i++)
      printf("%d ",h[i]);
   
  }


void top_heap(int *h, int n)
{
	int i,j,k,key;
	for(k=1;k<=n;k++)
	{
		i=k;
		
		key= h[i];
		
		j=(i-1)/2; //find the parent
		//while key is greater than the parent
		//or root is reached (i=0)
		while((i>0)&&(key > h[j]))
		{
			h[i]=h[j];//move the parent down
			i=j;
			j=(i-1)/2;
		}
		h[i]=key;
	}
			
}

void bot_heap(int *h, int n) 
{
	
  //n is the index of the last element
	int k,i,j,key;

	for(k=(n-1)/2; k>=0;k--)   //n-1 is number of nodes as index starts with 0
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
			 break;	//!!!!remember
		}
     h[i]=key;//insert the key
	}	 
}

	
 














 













































      






















