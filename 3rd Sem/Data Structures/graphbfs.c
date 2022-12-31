#include <stdio.h>

void creategraph();
void printgraph();
/*int indegree(int );
int outdegree(int);*/
void bfs(int );
int connected();
void dfs(int);
int pop();
void push(int);
int isemptys();

void qinsert();
int qdelete();
int qisempty();


int n,a[50][50],visit[50];
int q[50];
int f,r;

void main()
{
	int v,i,x;
    f=-1;r=-1;
	
	printf("Enter the number of nodes or vertices..");
	scanf("%d",&n);
	creategraph();
	printf("The graph is..");
	printgraph();
	
	for(i=1;i<n;i++)
    visit[i]=0;	

	printf("Enter the start vertex for traversal....");
	scanf("%d",&v);
	
	printf("The graph traversed using BFS is ....");
	dfs(v);
	//bfs(v);
	
	printf("Check for Connectivity..");
	
	
       x= connected();
    
	if(x)
		printf("The graph is connected..");
	else 
	    printf("The graph is not connected..");
}

void creategraph()
{
 int i,j;
  while(1)
  {
  printf("Enter the source and destination ..");
  scanf("%d %d",&i,&j);
	
  if((i==0)&&(j==0))break;
  	a[i][j]=1;
	a[j][i]=1;
    }
}

void printgraph()
{int i,j;
  for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
		  printf("a[%d][%d] = %d\t ",i,j,a[i][j]);
	  printf("\n");
}

/*int indegree(int v)
{ int i, count=0;
	for(i=1;i<n;i++)
		if(a[i][v]==1) count++;
	return count;
	
}

int outdegree(int v)
{ int i, count=0;
	for(i=1;i<n;i++)
		if(a[v][i]==1) count++;
	return count;
}*/
//graph traversal technique
int stack[100];int top=-1;
void push(int ele){
	top++;
	stack[top] = ele;
}
int pop(){
	int x=stack[top];
	top--;
	return x;
}
int isemptys(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void bfs(int v)
{
	int w;
	visit[v]=1; // visited v node.
	printf("%d",v);
	qinsert(v);
	
	while(!qisempty())
	{
		v=qdelete();
		
	  for(w=1;w<=n;w++)
		if((a[v][w]==1)&& visit[w]==0)
		{
			visit[w]=1;
			printf("%d",w);
			qinsert(w);
		}
			
    }
}

void dfs(int v)
{
	// for(int i=0;i<n;i++){
	// 	visit[i]=0;
	// }
	// int w;
	// visit[v]=1; // visited v node.
	// printf("%d",v);
	// push(v);
	
	// while(!isemptys())
	// {
	// 	v=pop();
		
	//   for(w=1;w<=n;w++)
	// 	if((a[v][w]==1)&& visit[w]==0)
	// 	{
	// 		visit[w]=1;
	// 		printf("%d",w);
	// 		push(w);
	// 	}
			
    // }
	printf("%d",v);
	visit[v]=1;
	push(v);
	while(!isemptys()){
		int x=pop();
		if(!visit[x]){
			visit[x]=1;
			printf("%d",x);
			for(int i=0;i<n;i++){
				if(!visit[x]){
					push(i);
				}
			}
		}
	}
}

//check graph connetivity for an undirected graph.

int connected()
{
	int i;
	for(i=1;i<=n;i++)
		visit[i]=0;
	
	
	bfs(1);
	
	for(i=1;i<=n;i++)
		if(visit[i]==0)
			return 0;
	return 1;
}
	
void qinsert(int v)
{   
    if((f==-1)&&(r==-1)) f++;
    	q[++r]=v;
		
}

int qdelete()
{
	int w;
	w=q[f];
	if(f==r) {f=-1;r=-1;}
	else f++;
	return w;
}

int qisempty()
{
	if((f==-1) && (r==-1))return 1;
	else return 0;
}

//detect cycle:
// int dfs(int v, int adj[5][5], int visited[5], int n, int p)
// {
//     visited[v] = 1;
//     for(int i=0; i<n; i++)
//     {
//         if(adj[v][i])
//         {
//           if(i != p)
//           {
//               if(visited[i]) return 1;
//               int k = dfs(i ,adj, visited, n, v);
//               if(k) return 1;
//           }
//         }
//     }
//     return 0;
// }


// int main()
// {
//     int adj[5][5];
//     int visited[5] = {0};
//     int n;
//     printf("\nEnter the number of vertices\n");
//     scanf("%d", &n);
//     printf("\nEnter the adjacency matrix\n");

//     for(int i=0; i<n; i++)
//     for(int j=0; j<n; j++)
//         scanf("%d", &adj[i][j]);

//     int res = dfs(0, adj, visited, n, -1);
//     if(res)
//         printf("\nGraph has a cycle!\n");
//     else
//         printf("\nIt has no cycle\n");

//     return 0;
// }