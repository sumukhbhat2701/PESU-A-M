#include "interface.h"

Graph::Graph(const int n)
: n(n)
{ 
    (this->graph).reserve(n);
}

Graph::~Graph()
{
}

void Graph::connect(const int u, const int v)
{
    if(find(graph[u].begin(), graph[u].end(), v) == graph[u].end())
        graph[u].push_back(v);

    if(find(graph[v].begin(), graph[v].end(), u) == graph[v].end())
        graph[v].push_back(u);
    
    if(V.find(u) == V.end())
    {
        V.insert(u);
        colors.insert({u, -1});
    }

    if(V.find(v) == V.end())
    {
        V.insert(v);
        colors.insert({v, -1});
    }
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

bool Graph::isConnected(const int u, const int v)
{
    for(int i = 0; i<graph[u].size(); ++i)
    {
        if(graph[u][i] == v)
            return 1;
    }
    return 0;
}


void Graph::vertexColoring(int color)
{
    if(color == 0)
    {
        for(int i = 0; i<colors.size(); ++i)
        {
            colors[i] = -1;
        }

        done = false;
        
        for(auto i: V)
        {
            degrees.insert({i, 0});
        }

        for (auto i: V)
		{
            for (auto j: V)
			{
                if(isConnected(i, j))
				{
                        degrees[i]++;
                }
            }
        }
    }

    color++;

	int vertex_max = 0, max_deg = 0;
		

	for (int i = 0; i < n; i++)
	{
        if (colors.find(i)->second == -1) 
        {
			if (max_deg < degrees[i]) 
            {
				max_deg = degrees[i];
				vertex_max = i;
			}
		}
    }

    colors[vertex_max] = color;
    cout<<vertex_max<<" is colored with c"<<colors[vertex_max]<<endl;

    for(auto i: V)
    {
        if(i!=vertex_max && find(graph[vertex_max].begin(), graph[vertex_max].end(), i) == graph[vertex_max].end() && colors.find(i)->second == -1)
        {
            int count = 0;
            for(auto j: V)
            {
                count++;
                if(find(graph[i].begin(), graph[i].end(), j) != graph[i].end() && colors[j] == colors[vertex_max]) 
                    done = true;
                
                if (count == n - 1 && !done) 
                {
                    colors[i] = color;
                    cout << i <<" is colored with c"<< colors[i] << endl;
                    done = false;
                }
				else if (count == n - 1) 
                    done = false;                
            }
        }
    }

    for(auto i: colors)
    {   
        if(i.second == -1)
        {
            vertexColoring(color);
            return;
        }
    }
    cout<<"All vertices colored successfully with chromatic number = "<<color<<endl;
}