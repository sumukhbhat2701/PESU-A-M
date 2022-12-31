#ifndef FLEURYS_ALGO_H
#define FLEURYS_ALGO_H
#include<vector>
#include<iostream>
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

        int findEuler(vector<int>& soln);
        void connect(const int u, const int v);
        void disconnect(const int u, const int v);
        void dfs(const int s, int* visited);
        void printGraph();
        void printEuler(const vector<int>& soln);
};

#endif
