#ifndef TARZANS_ALGO_H
#define TARZANS_ALGO_H
#include<bits/stdc++.h>
using namespace std;
#define MAX 9999
#define DEBUG 0

class Graph
{
    int n;
    vector<vector<int>> graph;

    public:
        Graph(): n(0) {}
        
        Graph(int n);

        ~Graph();

        void findArticulation(vector<int>& soln);
        void connect(const int u, const int v);
        void dfs(int u, int par, int& time, vector<int>& visited, vector<int>& disc, vector<int>& low, vector<int>& flag);
        void printGraph();
};

#endif