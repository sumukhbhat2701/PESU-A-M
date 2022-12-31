#ifndef A3_H
#define A3_H

// structure with values of maximum capacities, a,b,c in maxA,maxB and maxC and volume at any number transitions in vA,vB and vC
// fn_index is to keep track of the last transition function applied to the state  
// move is to keep track of the transition that was applied to previous state to reach that state for printing the desired output
// values of move:
// -1: for src and goal states ; 12: A2B ; 13: A2C ; 23: B2C ; 21: B2A ; 31:C2A ; 32: C2B
struct state
{
    int vA,vB,vC,maxA,maxB,maxC;
    int fn_index, move;
};
typedef struct state state_t; 

// a doubly linked list node structure with data field as state structure
struct node
{
    struct node* next;
    struct node* prev;
    state_t st;
};
typedef struct node node_t;

// a doubly linked list structure with both head and tail
struct dlist
{
    node_t *head;
    node_t *tail;
};
typedef struct dlist list_t;

// linked list functions
list_t* new_list();
void end_insertion(list_t* dll,const state_t* st);
void end_deletion(list_t* dll);
void print_list(const list_t* dll);
int is_unique(const list_t* dll, const state_t* st);
void delete_list(list_t* dll);

// functions with respect to state structures
state_t new_state(const int a,const int b,const int c,const int X,const int Y,const int Z);
void print_state(const state_t* st);
int is_valid(const state_t* st);
int is_equal(const state_t* st1, const state_t* st2);
int state_space_search(state_t* start, state_t* goal);

// transition functions
void B2C(const state_t *st1, state_t *st2);
void C2A(const state_t *st1, state_t *st2);
void B2A(const state_t *st1, state_t *st2);
void A2C(const state_t *st1, state_t *st2);
void A2B(const state_t *st1, state_t *st2);
void C2B(const state_t *st1, state_t *st2);

// transition callback array with 6 transition functions above
extern void (*transition[])(const state_t *st1, state_t *st2);

#endif