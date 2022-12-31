#ifndef A2_H
#define A2_H
#include<stdio.h>
#include<stdlib.h>
#define DEBUG 0

struct node
{
    int v, w;
    struct node *next;
};
typedef struct node node_t;

struct list
{
    node_t *head;
};
typedef struct list list_t;

struct graph
{
    list_t *adjlist;
    int n;
};
typedef struct graph graph_t;

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

graph_t* new_graph(const int n);
void insert_edge(graph_t* G, const int src, const int dst, const int w);
void front_insertion(list_t* list, node_t* node);
void delete_graph(graph_t* G);
void free_list(list_t* list);
void print_graph(const graph_t* G);
void print_list(const list_t* list);
pq_t* new_pq(int n);
void print_pq(const pq_t* Q);
void free_pq(pq_t* pq);
void heapify(pq_t* pq,int n);
void create_heap(pq_t* heap);
int delete_min(pq_t* pq);
void update_pq(pq_t* pq, int v, int d, int p);
int exists(pq_t* Q, int v);
int find_position(pq_t* Q, int v);
void single_source_dijkstras(graph_t* G, int src);
graph_t* reverse_edges(graph_t* G);
void single_dest_dijkstras(graph_t* G, int dst);
void print_route(pq_t* path, int v);


#endif