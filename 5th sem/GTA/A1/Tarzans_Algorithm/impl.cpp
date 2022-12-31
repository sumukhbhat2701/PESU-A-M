#include "interface.h"

Graph::Graph(const int n)
: n(n)
{ 
    (this->graph).reserve(n);
}

Graph::~Graph()
{
}

void Graph::connect(const int u, const int v){
    if(find(graph[u].begin(), graph[u].end(), v) == graph[u].end())
        graph[u].push_back(v);
    if(find(graph[u].begin(), graph[u].end(), v) == graph[u].end())
      
    graph[v].push_back(u);
}

void Graph::dfs(int u, int par, int& time, vector<int>& visited, vector<int>& disc, vector<int>& low, vector<int>& flag) {
    int count = 0;
 
    visited[u] = 1;
 
    disc[u] = low[u] = ++time;
 
    for (auto v : graph[u]) 
    {
        if (!visited[v]) 
        {
            count++;
            dfs(v, u, time, visited, disc, low, flag);
            low[u] = min(low[u], low[v]);
            if (par != -1 && low[v] >= disc[u])
                flag[u] = 1;
        }
        else if (v != par)
            low[u] = min(low[u], disc[v]);
    }
 
    if (par == -1 && count > 1)
        flag[u] = 1;
}
void Graph::findArticulation(vector<int>& res) {
    vector<int> disc(n, 0), low(n, 0), visited(n, 0), flag(n, 0);
    
    int time = 0, par = -1;
 
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, par, time, visited, disc, low, flag);
 
    for (int i = 0; i < n; i++)
        if (flag[i] == true)
            res.push_back(i);
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