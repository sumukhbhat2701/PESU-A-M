#ifndef CHINESE_POSTMAN
#define CHINESE_POSTMAN

#include<bits/stdc++.h>
#define DEBUG 0
#define MAX 99999
using namespace std;

struct pqnode
{
    int v,d,p;
};
typedef struct pqnode pqnode_t;

struct pq
{
    int max_size, size;
    pqnode_t *pq;
};
typedef struct pq pq_t;

class Graph
{
    int n;
    vector<vector<vector<int>>> graph;
    int total_weight;

    public:
        Graph(): n(0) {}
        
        Graph(int n);

        ~Graph();

        vector<vector<pair<int, int>>> findPairs(vector<int> vertices, vector<pair<int, int>> list);
        void ChinesePostman();
        void connect(const int u, const int v, const int w);
        void disconnect(const int u, const int v);
        void printGraph();
        // dijstras
		vector<int> distance(int src, int dst);
		void dfs(const int s, int* visited);
		void printEuler(const vector<int>& soln);
        void Euler();
};






#endif