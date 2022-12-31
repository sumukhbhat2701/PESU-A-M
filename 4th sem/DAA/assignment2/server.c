#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

graph_t* new_graph(const int n)
{
    graph_t* G = (graph_t *)malloc(sizeof(graph_t));
    G->adjlist = (list_t *)malloc((n+1)*sizeof(list_t));
    G->n = n;
    for(int v=1;v<=n;v++)
    {
        ((G->adjlist + v)->head) = NULL;
    }
    
    return G;
}

void insert_edge(graph_t* G, const int src, const int dst, const int w)
{
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new->v = dst;
    new->w = w;
    new->next = NULL;
    front_insertion((G->adjlist) + src,new); 
}

void front_insertion(list_t* list, node_t* node)
{
    if(list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
}

void delete_graph(graph_t* G)
{
    for(int i=1;i<=(G->n);i++)
    {
        if((G->adjlist + i)->head!=NULL)
        {
            free_list(G->adjlist+i);
        }
    }
    free(G);
}

void free_list(list_t* list)
{
    if(list->head->next == NULL)
    {
        free(list->head);
    }
    else
    {
        node_t* p1 = list->head; node_t* p2 = list->head->next;
        while(p2!=NULL)
        {
            free(p1);
            p1 = p2;
            p2 = p2->next;
        }
        free(p1);
    }
}

void print_graph(const graph_t* G)
{
    for(int i=1;i<=(G->n);i++)
    {
        printf("%d -> ",i); print_list(G->adjlist + i);
    }
    
}

void print_list(const list_t* list)
{
    for(node_t* temp = list->head; temp!=NULL; temp=temp->next)
    {
        printf("v=%d w=%d; ",temp->v,temp->w);
    }
    printf("\n");
    
}

pq_t* new_pq(int n)
{
    pq_t* new = (pq_t *)malloc(sizeof(pq_t));
    new->size = n;
    new->max_size = n;
    new->pq = (pqnode_t *)malloc(sizeof(pqnode_t)*(n+1));
    for(int i=1;i<=n;i++)
    {
        new->pq[i].v = i;
        new->pq[i].p = -1;
        new->pq[i].d = INT_MAX;
    }
    return new;
}

void free_pq(pq_t* pq)
{
    free(pq->pq);
    free(pq);
}

void heapify(pq_t* pq,int n)
{
    int j = 1;
    pqnode_t key = pq->pq[j];
    int i = 2*j;
    while(i<=n)
    {
        if(i+1 <= n)
        {
            if(pq->pq[i+1].d < pq->pq[i].d)
            {
                i++;
            }
        }
        if(key.d > pq->pq[i].d)
        {
            pq->pq[j] = pq->pq[i];
            j = i;
            i = 2*j; 
        }
        else 
            break;
    }
    pq->pq[j] = key;
}

void create_heap(pq_t* heap)
{   
    int i,j;
    pqnode_t key;
    for(int k=(heap->size)/2;k>=1;k--)
    {
        j = k;
        key = (heap->pq)[k];
        i = 2*j;
        while(i<=(heap->size))
        {
            if(i+1 <= heap->size)
            {
                if(heap->pq[i+1].d < heap->pq[i].d)
                {
                    i++;
                }
            }
            if(key.d > heap->pq[i].d)
            {
                heap->pq[j] = heap->pq[i];
                j = i;
                i = 2*j;
            }
            else break;
        }
        heap->pq[j] = key;
    }

}

int delete_min(pq_t* pq)
{
    pqnode_t temp = pq->pq[1];
    int u = temp.v;
    pq->pq[1] = pq->pq[pq->size];
    pq->pq[pq->size] = temp;

    pq->size--;

    heapify(pq,pq->size);

    return u;
}

void update_pq(pq_t* pq, int v, int d, int p)
{
    for(int i=1;i<=pq->size;i++)
    {
        if(pq->pq[i].v == v)
        {
            pq->pq[i].d = d;
            pq->pq[i].p = p;
            break;
        }
    }
    create_heap(pq);
}

void print_pq(const pq_t* Q)
{
    for(int i=1;i<=Q->size;i++)
    {
        printf("%d : d=%d p=%d\n",Q->pq[i].v,Q->pq[i].d,Q->pq[i].p);
    }
}

int find_position(pq_t* Q, int v)
{   
    for(int i=1; i<=Q->max_size; i++)
    {
        if(Q->pq[i].v == v)
            return i;
    }
    return -1;
}

int exists(pq_t* Q, int v)
{
    for(int i=1; i<=Q->size; i++)
    {
        if(Q->pq[i].v == v)
        {
            return 1;
        }
    }
    return 0;
}

void single_source_dijkstras(graph_t* G, int s)
{
    pq_t* Q = new_pq(G->n);
    Q->pq[s].d = 0;
    
    create_heap(Q);
    
    node_t* temp; int u, index1, index2;
    for(int j=0;j<(G->n - 1);j++)
    {
        u = delete_min(Q);

        temp = G->adjlist[u].head;
        while(temp!=NULL)
        {
            index1 = find_position(Q,temp->v); index2 = find_position(Q,u);
            if(exists(Q,temp->v) && (Q->pq[index1].d > (Q->pq[index2].d + temp->w)))
            {
                update_pq(Q,temp->v,Q->pq[index2].d + temp->w,u);
            }
            temp = temp->next;
        }
    }

    int index;
    for(int i=1;i<=G->n;i++)
    {
        if (i != s)
        {
            printf("%d ",i);
            index = find_position(Q,i);
            if(Q->pq[index].d == INT_MAX)  printf("NO PATH\n");
            else
            {
                print_route(Q, i);
                printf("%d\n",Q->pq[index].d);
            }
        }
    }

    free_pq(Q);
}

graph_t* reverse_edges(graph_t* G)
{
    graph_t* R = new_graph(G->n);
    node_t* temp;
    int u, v;
    for(int i=1;i<=R->n;i++)
    {
        temp = G->adjlist[i].head;
        while(temp!=NULL)
        {
            insert_edge(R,temp->v,i,temp->w);
            temp = temp->next; 
        }
    }
    return R;
}

void single_dest_dijkstras(graph_t* G, int dst)
{
    graph_t* R = reverse_edges(G);
    if(DEBUG) { printf("\nReversed Graph:\n"); print_graph(R); printf("\n"); }
    single_source_dijkstras(R, R->n);
}

void print_route(pq_t* Q, int v)
{
    if (v > 0) 
    {
        printf("%d ",v);
        int i = find_position(Q,v);
        if(i == -1) return;
        print_route(Q, Q->pq[i].p);
    }    
}
