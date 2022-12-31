#ifndef BARUVKAS_ALGO_H
#define BARUVKAS_ALGO_H
#include<bits/stdc++.h>
using namespace std;
#define MAX 999999
#define DEBUG 0
#include <chrono>
using namespace chrono;

class Graph
{
    int n; int e;
    vector<vector<vector<int>>> graph;
    vector<vector<int>> E;
    vector< pair<int, pair<int, int>> > edgePairs;
    list<int> *adj;

    public:
        Graph(): n(0), e(0) {}
        
        Graph(int n);

        ~Graph();

        void connect(const int u, const int v, const int w);
        void printGraph();
        int BaruvkasMST(vector<vector<int>>& mst);
        int PrimsMST(vector<vector<int>>& mst);
        int KrushkalsMST(vector<vector<int>>& mst);
        int ReverseDeleteMST(vector<vector<int>>& mst);
        void printMST(vector<vector<int>>& mst);
        void addEdge(int u, int v, int w);
        void DFS(int v, bool visited[]);
        bool isConnected();
};

class Sets
{
    int n;
    vector<vector<int>> sets;
    public:
        Sets(): n(0) {}
        Sets(int n);
        ~Sets() {}

        int Find(int);
        void Union(int, int);
};

struct DisjointSets
{
    int *parent, *rnk;
    int n;
  
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
  
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
  
            parent[i] = i;
        }
    }
  
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
  
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
  
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else 
            parent[x] = y;
  
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

#endif
