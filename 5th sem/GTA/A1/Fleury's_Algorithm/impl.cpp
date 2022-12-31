#include "interface.h"

Graph::Graph(const int n)
: n(n)
{ 
    (this->graph).reserve(n);
}

Graph::~Graph()
{
}

void Graph::dfs(const int s, int* visited)
{
    visited[s] = 1;
    for(int n = 0; n<graph[s].size(); n++)
    {
        if(!visited[graph[s][n]])
            dfs(graph[s][n], visited);
    }
}

void Graph::connect(const int u, const int v)
{
    graph[u].push_back(v);
}

void Graph::disconnect(const int u, const int v)
{
    int delPos = -1;
    for(int i = 0; i<graph[u].size(); i++)
        if(graph[u][i] == v)
            {
                delPos = i;
                break;
            }
    if(delPos != -1)
    {
        graph[u].erase(graph[u].begin() + delPos);
    }
}

bool isEmpty(vector<vector<int>>& graph, int n)
{
    for(int i = 0; i<n; i++)
        if(graph[i].size()!=0)
            return 0;
    return 1;
}

void Graph::printGraph()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<graph[i].size(); j++)
        {
            cout<<i<<" -> "<<graph[i][j]<<endl;
        }
    }
}

void print(vector<vector<int>>& graph, int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<i<<" ";
        for(int j = 0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}

void Graph::printEuler(const vector<int>& soln)
{
    for(int i = 0; i<soln.size()-1; i++)
        cout<<soln[i]<<" -> ";
    cout<< soln[soln.size() - 1] << endl;
}

int Graph::findEuler(vector<int>& soln)
{
    int start, u, v, oddDegrees = 0, oddVertex, flag, ptr, visited[n];
    for(int i = 0; i<n; i++)
    { 
        if(graph[i].size() % 2 != 0)
        {
            oddDegrees++;
            oddVertex = i;
        }
    }
    if(oddDegrees == 0) // Eulerian Graph
    {
        flag = 1;
        start = 0;
    }
    else if(oddDegrees == 2) // Semi-Eulerian Graph
    {
        flag = 2;
        start = oddVertex;
    }
    else    // Non-Eulerian graph
        return -1;
    
    ptr = start;
    soln.push_back(start);

    while(!isEmpty(graph, n))
    {
       if(graph[ptr].size() != 0)
       {
            int allBridges = 1;
            for(int i = 0; i<graph[ptr].size(); i++)
            {
                for(int k = 0; k<n; k++)
                    visited[k] = 0;

                u = ptr; v = graph[ptr][i];

                disconnect(u, v);
                disconnect(v, u);
                
                dfs(u, visited);

                if(visited[v])
                {
                    soln.push_back(v);
                    allBridges = 0;
                    ptr = v;
                    break;
                }
                else
                {
                    connect(u, v);
                    connect(v, u);
                }
            }
            if(allBridges)
            {
                u = ptr; v = graph[ptr][0];
                disconnect(u, v);
                disconnect(v, u);
                soln.push_back(v);
                ptr = v;
            }
       }
       else
            break;
    }
    return flag;
}


