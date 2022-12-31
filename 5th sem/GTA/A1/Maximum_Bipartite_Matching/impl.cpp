#include "interface.h"

Graph::Graph(const int m, const int n)
: m(m), n(n)
{ 
    (this->graph).reserve(m);
}

Graph::~Graph()
{
}

bool Graph::dfs(int u, vector<bool> visited, vector<int> matchR)
{
    for (int v = 0; v < graph[u].size(); v++)
    {
        if (!visited[graph[u][v] - n])
        {
            visited[graph[u][v] - n] = true;

            if (matchR[graph[u][v] - n] < 0 || dfs(matchR[graph[u][v] - n], visited, matchR))
            {
                matchR[graph[u][v] - n] = u;
                return true;
            }
        }
    }
    return false;
}

void Graph::connect(const int u, const int v)
{
    graph[u].push_back(v);
}

int Graph::maxBM()
{
    vector<int> matchR(n, -1);

    int result = 0;
    for (int u = 0; u < m; u++)
    {
        vector<bool> visited(n, 0); 
        if (dfs(u, visited, matchR))
            result++;
    }
    return result;
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