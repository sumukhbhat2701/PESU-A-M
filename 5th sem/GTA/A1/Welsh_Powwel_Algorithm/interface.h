#ifndef WELSH_POWWEL_ALGO_H
#define WELSH_POWWEL_ALGO_H
#include<bits/stdc++.h>
using namespace std;
#define MAX 9999
#define DEBUG 0

class Graph
{
    int n;
    vector<vector<int>> graph;
    unordered_map<int, int> colors;
    unordered_set<int> V;
    unordered_map<int, int> degrees;
    unordered_map<int, int> temp;
    bool done = false;

    public:
        Graph(): n(0) {}
        
        Graph(int n);

        ~Graph();

        void vertexColoring(int color);
        void connect(const int u, const int v);
        bool isConnected(const int u, const int v);
        void printGraph();
};

#endif