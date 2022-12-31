#ifndef MAX_BIPARTITATE_MATCH
#define MAX_BIPARTITATE_MATCH
#include<bits/stdc++.h>
using namespace std;
#define MAX 9999
#define DEBUG 0

class Graph
{
    int n, m;
    vector<vector<int>> graph;

    public:
        Graph(): n(0) {}
        
        Graph(int m, int n);

        ~Graph();

        void connect(const int u, const int v);
        int maxBM();
        void printGraph();
        bool dfs(int u, vector<bool> visited, vector<int> matchR);
        
};

#endif