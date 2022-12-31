#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	//TODO
	int *myQueue = (int *)malloc(n*sizeof(int));
	int *visitedStatus = (int *)calloc(n,sizeof(int));
	int front = -1;
	int rear = -1;

	//starting node
	visitedStatus[v]=1;

	//enqueue starting node
	if((front==-1)&&(rear==-1)) 
		front++;
    myQueue[++rear] = v;
	
	while(front!=-1 || rear!=-1)
	{
		//dequeue
		v = myQueue[front];
		if(front==rear) 
		{
			front = -1;
			rear = -1;
		}
		else 
			front++;
		
	  	for(int node=0;node<n;node++)
		if((graph[v][node]==1)&& visitedStatus[node]==0)
		{
			visitedStatus[node]=1;
			//enqueue
			if((front==-1)&&(rear==-1)) 
				front++;
			myQueue[++rear] = node;
		}		
    }

	if(visitedStatus[u]==1)
	{
		return 1;
	}
	else{
		return 0;
	}
	free(myQueue);
	free(visitedStatus);
}	
