#include "interface.h"

Graph::Graph(const int n)
: n(n), total_weight(0)
{ 
    (this->graph).reserve(n);
}

Graph::~Graph()
{
}

void Graph::connect(const int u, const int v, const int w)
{
    vector<int> edge;
    edge.push_back(v);
    edge.push_back(w);
    graph[u].push_back(edge);
	total_weight += w;
}

void Graph::disconnect(const int u, const int v)
{
    int delPos = -1;
    for(int i = 0; i<graph[u].size(); i++)
        if(graph[u][i][0] == v)
            {
                delPos = i;
                break;
            }
    if(delPos != -1)
    {
        graph[u].erase(graph[u].begin() + delPos);
    }
}


void Graph::printGraph()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<graph[i].size(); j++)
        {
            cout<<i<<" -> "<<graph[i][j][0]<<" ; "<<graph[i][j][1]<<endl;
        }
    }
}

vector<vector<pair<int, int>>> pairing(vector<int> vertices, vector<pair<int, int>> list)
{
    vector<vector<pair<int, int>>> pairs;
    if (vertices.empty()) {
        pairs.push_back(list);
        return pairs;
    }
    else {
        auto it = min_element(vertices.begin(), vertices.end());
        int i = *it;
        vertices.erase(it);
        for (int index = 0; index < vertices.size(); index++) {
            int j = vertices[index];
            vertices.erase(vertices.begin() + index);

            pair<int, int> pair(i, j);
            list.push_back(pair);

            vector<vector<std::pair<int, int>>> r = pairing(vertices, list);

            list.erase(list.end() - 1);

            pairs.insert(pairs.end(), r.begin(), r.end());

            vertices.insert(vertices.begin(), j);
        }
    }
    return pairs;
}

void get_route(int src, int v, vector<int> parent, vector<int>& path)
{
	if(v!=-1)
	{
		path.push_back(v);
		get_route(src, parent[v], parent, path);
	}
}

vector<int> Graph::distance(int src, int dst)
{
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
  
    vector<int> dist(n, INT_MAX);
	vector<int> parent(n, -1);
  
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();
  
        vector<vector<int>>::iterator i;
        for (i = graph[u].begin(); i != graph[u].end(); ++i)
        {

            int v = (*i)[0];
            int weight = (*i)[1];
  
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
				parent[v] = u;
            }
        }
    }

	vector<int> path;
	get_route(src, dst, parent, path);
	reverse(path.begin(), path.end());
	path.push_back(dist[dst]);
    return path;
}

void Graph::dfs(const int s, int* visited)
{
    visited[s] = 1;
    for(int n = 0; n<graph[s].size(); n++)
    {
        if(!visited[graph[s][n][0]])
            dfs(graph[s][n][0], visited);
    }
}

void Graph::printEuler(const vector<int>& soln)
{
    for(int i = 0; i<soln.size()-1; i++)
        cout<<soln[i]<<" -> ";
    cout<< soln[soln.size() - 1] << endl;
}

bool isEmpty(vector<vector<vector<int>>>& graph, int n)
{
    for(int i = 0; i<n; i++)
        if(graph[i].size()!=0)
            return 0;
    return 1;
}

void Graph::Euler()
{
	vector<int> soln;
    int start, u, v, w, oddDegrees = 0, oddVertex, ptr, visited[n];
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
        start = 0;
    }
    else cout<<"Still Non-Eulerian Graph"<<endl;
    
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

                u = ptr; v = graph[ptr][i][0];

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
                    connect(u, v, w);
                    connect(v, u, w);
                }
            }
            if(allBridges)
            {
                u = ptr; v = graph[ptr][0][0]; w = graph[ptr][0][1];
                disconnect(u, v);
                disconnect(v, u);
                soln.push_back(v);
                ptr = v;
            }
       }
       else
            break;
    }
	printEuler(soln);
}



void Graph::ChinesePostman()
{
	vector<int> degrees(n, 0);
	for(int i = 0; i<n; ++i)
	{
		degrees[i] = graph[i].size();
	}
	vector<int> oddVertices(0);
	for(int i = 0; i<degrees.size(); ++i)
	{
		if(degrees[i] % 2 != 0)
			oddVertices.push_back(i);
	}
	if(oddVertices.size() == 0)
	{
		cout<<"Minimum extra cost needed to traverse all edges = 0"<<endl;
		cout<<"The graph already has a Euler path:\n";
		Euler();
		return;
	}
	vector<vector<pair<int, int>>> pairs = pairing(oddVertices, vector<pair<int, int>>());
	int min_idx = 0, min_sum = INT_MAX;
	vector<int> temp;
	for(int i = 0; i<pairs.size(); ++i)
	{
		vector<pair<int, int>> partition = pairs[i];
		int sum = 0;
		for(auto p: partition)
		{
			int u = p.first;
			int v = p.second;
			temp = distance(u, v);
			sum += temp[temp.size() - 1];
			
		}
		if(sum < min_sum)
		{
			min_idx = i;
			min_sum = sum;
		}
	}
	vector<pair<int, int>> addendum = pairs[min_idx];

	cout<<"We add the following undirected edges : "<<endl;
	for(auto p: addendum)
	{
		int u = p.first;
		int v = p.second;
		temp = distance(u, v);
		temp.pop_back();
		for(int i = 0; i<temp.size()-1; ++i)
		{
			int w;
			for(int i = 0; i < graph[u].size(); ++i)
			{
				if(graph[u][i][0] == v)
				{
					w = graph[u][i][1];
					break;
				}
			}
			cout<<"("<<temp[i]<<" "<<temp[i+1]<<") "<<endl;
			connect(temp[i], temp[i+1], w);
			connect(temp[i+1], temp[i], w);
		}
	}

	cout<<"Minimum extra cost needed to traverse all edges = "<<min_sum<<endl;
	cout<<"Optimal route covering all the edges: "<<endl;

	Euler();

}