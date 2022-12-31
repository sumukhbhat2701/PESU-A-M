#include "interface.h"

Graph::Graph(const int n)
: n(n), e(0)
{ 
    (this->graph).reserve(n);
    adj = new list<int>[n];
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int u, int v, int w)
{
    edgePairs.push_back({w, {u, v}});
}

void Graph::connect(const int u, const int v, const int w)
{
    vector<int> edge;
    edge.push_back(v);
    edge.push_back(w);
    graph[u].push_back(edge);
    edge.pop_back();
    edge.pop_back();
    edge.push_back(u);
    edge.push_back(v);
    edge.push_back(w);

    E.push_back(edge);
    addEdge(u, v, w);
    adj[u].push_back(v);
    e++;
}


void Graph::printGraph()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<graph[i].size(); j++)
        {
            cout<<i<<" -> "<<graph[i][j][0]<<endl;
        }
    }
}

void Graph::printMST(vector<vector<int>>& mst)
{
    for(int i = 0; i<mst.size(); i++)
    {
        cout<<mst[i][0]<<" <-> "<<mst[i][1]<<endl;
    }
    
}

int Graph::BaruvkasMST(vector<vector<int>>& mst)
{
    Sets s(n);
    vector<int> min_(n, -1);
    int res = 0;

    int forest = n, s1 = 0, s2 = 0;
    while(forest > 1)
    {
        for(int i = 0; i<n; i++)
            min_[i] = -1;
        
        for(int i = 0; i<e; ++i)
        {
            s1 = s.Find(E[i][0]), s2 = s.Find(E[i][1]); 

            if(s1 != s2)
            {
                if(min_[s1] == -1 || E[min_[s1]][2] > E[i][2])
                    min_[s1] = i;

                if(min_[s2] == -1 || E[min_[s2]][2] > E[i][2])
                    min_[s2] = i;
                    
            }

        }

        vector<int> edge(2,0), redge(2,0);
        for(int i = 0; i<n; ++i)
        {
            if(min_[i] != -1)
            {
                s1 = s.Find(E[min_[i]][0]);
                s2 = s.Find(E[min_[i]][1]);

                if(s1 == s2)
                {
                    continue;
                }
                else
                {
                    edge[0] = E[min_[i]][0];
                    edge[1] = E[min_[i]][1];

                    redge[0] = E[min_[i]][1];
                    redge[1] = E[min_[i]][0];
                    
                    if(find(mst.begin(), mst.end(), edge) == mst.end() && find(mst.begin(), mst.end(), redge) == mst.end())
                    {
                        mst.push_back(edge);
                        res+=E[min_[i]][2];
                    }
                    s.Union(s1, s2);
                    forest--;
                }
            }
        }
    }

    return res;

}

int Graph::KrushkalsMST(vector<vector<int>>& mst)
{
    
    int mst_wt = 0;
  
    sort(edgePairs.begin(), edgePairs.end());
  
    DisjointSets ds(n);
  
    vector< pair<int, pair<int, int>> >::iterator it;
    for (it=edgePairs.begin(); it!=edgePairs.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
  
        int set_u = ds.find(u);
        int set_v = ds.find(v);
  

        if (set_u != set_v)
        {
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            mst.push_back(edge);
            mst_wt += it->first;
            ds.merge(set_u, set_v);
        }
    }
  
    return mst_wt;

}

void Graph::DFS(int v, bool visited[])
{
    visited[v] = true;
  

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}
  
bool Graph::isConnected()
{
    bool visited[n];
    for(int i = 0; i<n; ++i)
        visited[i] = false;
  
    DFS(0, visited);
  
    for (int i=1; i<n; i++)
        if (visited[i] == false)
            return false;
  
    return true;
}

int Graph::ReverseDeleteMST(vector<vector<int>>& mst)
{
    sort(edgePairs.begin(), edgePairs.end());
  
    int mst_wt = 0;  
    

    for (int i=edgePairs.size()-1; i>=0; i--)
    {
        int u = edgePairs[i].second.first;
        int v = edgePairs[i].second.second;
  
        adj[u].remove(v);
        adj[v].remove(u);
  

        if (!isConnected())
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
  
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            vector<int> redge = {v,u};
            if(find(mst.begin(),mst.end(), redge) == mst.end() && find(mst.begin(),mst.end(), edge) == mst.end()) 
            {
                mst.push_back(edge);
                mst_wt += edgePairs[i].first;
            }
        }
    }
  
  
    return mst_wt/2;
}

int Graph::PrimsMST(vector<vector<int>>& mst)
{

    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
 
    int src = 0; 
    int res = 0;
 
    vector<int> key(n, INT_MAX);
 
    vector<int> parent(n, -1);
 
    vector<bool> inMST(n, false);
 

    pq.push(make_pair(0, src));
    key[src] = 0;
 
    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();

          if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;  
 
        list< pair<int, int> >::iterator i;
        for (int i = 0; i<graph[u].size(); ++i)
        {

            int v = graph[u][i][0];
            int weight = graph[u][i][1];
 

            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v)); 
                parent[v] = u;               
            }
        }
    }
    for (int i = 1; i < n; ++i)
        {
            vector<int> edge;
            edge.push_back(parent[i]);
            edge.push_back(i);
            mst.push_back(edge);
            res+=key[i];
        }
     
    return res;
}

Sets::Sets(int n)
{
    this->n = n;
    for(int i = 0; i<n; i++)
    {
        vector<int> new_ = {i, 0};
        sets.push_back(new_);
    }
}


int Sets::Find(int e)
{
    if(sets[e][0] != e)
        sets[e][0] = this->Find(sets[e][0]);
    
    return sets[e][0];
    return -1;
}

void Sets::Union(int e1, int e2)
{
    int root1 = Find(e1);
    int root2 = Find(e2);

    if(sets[root1][1] < sets[root2][1])
        sets[root1][0] = root2;
    else if(sets[root1][1] > sets[root2][1])
        sets[root2][0] = root1;
    else
    {
        sets[root2][0] == root1;
        sets[root1][1]++;
    }
}

