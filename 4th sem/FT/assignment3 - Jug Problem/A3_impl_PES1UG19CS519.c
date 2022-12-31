#include<stdio.h>
#include<stdlib.h>
#include "A3_header_PES1UG19CS519.h"

// allocate memory for a empty doubly linked lists, initialize and return it
list_t* new_list()
{
    list_t* dll = (list_t *)malloc(sizeof(list_t));
    dll->head = NULL;
    dll->tail = NULL;
    return dll;
}

// End insertion of a doubly linked list
void end_insertion(list_t* dll,const state_t* st)
{
    // creation of a new node
    node_t* new = (node_t *)malloc(sizeof(node_t));
    new->st = *st;
    new->next = NULL;
    new->prev = NULL;
    // if list is empty
    if(dll->head == NULL)
    {
        dll->head = new;
        dll->tail = dll->head;
    }
    // if list is non empty
    else
    {
        dll->tail->next = new;
        new->prev = dll->tail;
        dll->tail = new;
    }
}

// Deletion of the last node in a doubly linked list
void end_deletion(list_t* dll)
{
    // If the list is not empty
    if(dll->head != NULL)
    {
        // if only one node in the list
        if(dll->head == dll->tail)
        {
            free(dll->head);
            dll->head = NULL;
            dll->tail = NULL;
        }
        // if more than 1 node in the list
        else
        {
            node_t* temp = dll->tail;
            dll->tail->prev->next = NULL;
            dll->tail = dll->tail->prev;
            free(temp);
        }
    }
   
}

// priniting the data field of the list using the print_state function
void print_list(const list_t* dll)
{
    for(node_t* temp = dll->head; temp!=NULL; temp=temp->next){
        print_state(&temp->st);
    }
    printf("\n");

}

// checking if a given state is already in the linked list or if it is unique after insertion
int is_unique(const list_t* dll, const state_t* st)
{   
    for(node_t* temp = dll->head; temp!=NULL; temp=temp->next){
        if(is_equal(&temp->st,st))
        {
            return 0;
        }
    }
    return 1;

}

// deleting/ freeing the space allocated for the list and all the nodes of the linked list
void delete_list(list_t* dll)
{
    // if the list is empty
    if(dll->head == NULL)
    {
        free(dll);
    }
    // if there is only one node in the list
    else if(dll->head == dll->tail)
    {
        free(dll->head);
        free(dll);
    }
    // if there are more than 1 nodes in the list, traverse and delete them all
    else
    {
        node_t* p1 = dll->head; node_t* p2 = dll->head->next;
        while(p2!=NULL)
        {
            free(p1);
            p1 = p2;
            p2 = p2->next;
        }
        free(p1);
        free(dll);
    }
}

// creaing a new state structure variable with the given values of capacties and volumes
state_t new_state(const int a,const int b,const int c,const int X,const int Y,const int Z)
{
    state_t st;
    st.vA = X;
    st.vB = Y;
    st.vC = Z;
    st.maxA = a;
    st.maxB = b;
    st.maxC = c;
    st.fn_index = 0;
    // move: -1 as start and goal states need not be printed in the output
    st.move = -1;
    return st;
}

// printing the transition that led to that state using the "move" field of the structure
// -1: for src and goal states ; 12: A2B ; 13: A2C ; 23: B2C ; 21: B2A ; 31:C2A ; 32: C2B
void print_state(const state_t* st)
{
    switch(st->move)
    {   
        case 12:{ printf("%c %c\n",'A','B'); break; }
        case 23:{ printf("%c %c\n",'B','C'); break; }
        case 31:{ printf("%c %c\n",'C','A'); break; }
        case 13:{ printf("%c %c\n",'A','C'); break; }
        case 32:{ printf("%c %c\n",'C','B'); break; }
        case 21:{ printf("%c %c\n",'B','A'); break; } 
        default: break;
    }
}

// Checking if a state is valid interms of its capacities and it's present volume i.e 0 <= volume at any time <= capacity 
int is_valid(const state_t* st)
{
    return ((st->vA >=0 && st->vA <= st->maxA) && (st->vB >=0 && st->vB <= st->maxB) && (st->vC >=0 && st->vC <= st->maxC)) ? 1 : 0;
}

// Checking if given 2 states are equal i.e all the volumes of any 2 given states are equal
int is_equal(const state_t* st1, const state_t* st2)
{
    return ((st1->vA == st2->vA) && (st1->vB == st2->vB) && (st1->vC == st2->vC)) ? 1 : 0;
}

// pour from B to C
void B2C(const state_t *st1, state_t *st2)
{
    // volume of A and capacities of A, B, C remain unchanged
    st2->vA = st1->vA;
    st2->maxA = st1->maxA;
    st2->maxB = st1->maxB;
    st2->maxC = st2->maxC;

    // if pouring B to C, exceeds the capacity of C, C would have maximum volume as its capacity and B's volume will be subtracted with difference of C's initial value and capacity
    if((st1->vB) + (st1->vC) > (st1->maxC))
    {
        st2->vB = st1->vB - (st1->maxC - st1->vC);
        st2->vC = st1->maxC; 
    }
    // otherwise B would become empty and its volume would be added to C
    else
    {
        st2->vC = st1->vC + st1->vB;
        st2->vB = 0;    
    }
    // initialize the fn_index to 0 to start from first callback funtion in the array
    st2->fn_index = 0;
    // move: 23 for B to C transition
    st2->move = 23;  
}

// pour from C to A
void C2A(const state_t *st1, state_t *st2)
{
    // volume of B and capacities of A, B, C remain unchanged
    st2->vB = st1->vB;
    st2->maxA = st1->maxA;
    st2->maxB = st1->maxB;
    st2->maxC = st2->maxC;

    // if pouring C to A, exceeds the capacity of A, A would have maximum volume as its capacity and C's volume will be subtracted with difference of A's initial value and capacity
    if((st1->vA) + (st1->vC) > (st1->maxA))
    {
        st2->vC = st1->vC - (st1->maxA - st1->vA);
        st2->vA = st1->maxA; 
    }
    // otherwise C would become empty and its volume would be added to A
    else
    {
        st2->vA = st1->vA + st1->vC;
        st2->vC = 0;    
    }
    // initialize the fn_index to 0 to start from first callback funtion in the array
    st2->fn_index = 0;
    // move: 31 for C to A transition
    st2->move = 31;
}

// pour from B to A
void B2A(const state_t *st1, state_t *st2)
{
    // volume of C and capacities of A, B, C remain unchanged
    st2->vC = st1->vC;
    st2->maxA = st1->maxA;
    st2->maxB = st1->maxB;
    st2->maxC = st2->maxC;

    // if pouring B to A, exceeds the capacity of A, A would have maximum volume as its capacity and B's volume will be subtracted with difference of A's initial value and capacity
    if((st1->vB) + (st1->vA) > (st1->maxA))
    {
        st2->vB = st1->vB - (st1->maxA - st1->vA);
        st2->vA = st1->maxA; 
    }
    // otherwise B would become empty and its volume would be added to A
    else
    {
        st2->vA = st1->vA + st1->vB;
        st2->vB = 0;    
    }
    // initialize the fn_index to 0 to start from first callback funtion in the array
    st2->fn_index = 0;
    // move: 21 for B to A transition
    st2->move = 21;
}

// pour from A to C
void A2C(const state_t *st1, state_t *st2)
{
    // volume of B and capacities of A, B, C remain unchanged
    st2->vB = st1->vB;
    st2->maxA = st1->maxA;
    st2->maxB = st1->maxB;
    st2->maxC = st2->maxC;

    // if pouring A to C, exceeds the capacity of C, C would have maximum volume as its capacity and A's volume will be subtracted with difference of C's initial value and capacity
    if((st1->vC) + (st1->vA) > (st1->maxC))
    {
        st2->vA = st1->vA - (st1->maxC - st1->vC);
        st2->vC = st1->maxC; 
    }
    // otherwise A would become empty and its volume would be added to C
    else
    {
        st2->vC = st1->vC + st1->vA;
        st2->vA = 0;    
    }
    // initialize the fn_index to 0 to start from first callback funtion in the array
    st2->fn_index = 0;
    // move: 13 for A to C transition
    st2->move = 13;
}

// pour from A to B
void A2B(const state_t *st1, state_t *st2)
{
    // volume of C and capacities of A, B, C remain unchanged
    st2->vC = st1->vC;
    st2->maxA = st1->maxA;
    st2->maxB = st1->maxB;
    st2->maxC = st2->maxC;

    // if pouring A to B, exceeds the capacity of B, B would have maximum volume as its capacity and A's volume will be subtracted with difference of B's initial value and capacity
    if((st1->vA) + (st1->vB) > (st1->maxB))
    {
        st2->vA = st1->vA - (st1->maxB - st1->vB);
        st2->vB = st1->maxB; 
    }
    // otherwise A would become empty and its volume would be added to B
    else
    {
        st2->vB = st1->vB + st1->vA;
        st2->vA = 0;    
    }
    // initialize the fn_index to 0 to start from first callback funtion in the array
    st2->fn_index = 0;
    // move: 12 for transition from A to B
    st2->move = 12;
}

// pour from C to B
void C2B(const state_t *st1, state_t *st2)
{
    // volume of A and capacities of A, B, C remain unchanged
    st2->vA = st1->vA;
    st2->maxA = st1->maxA;
    st2->maxB = st1->maxB;
    st2->maxC = st2->maxC;

    // if pouring C to B, exceeds the capacity of B, B would have maximum volume as its capacity and C's volume will be subtracted with difference of B's initial value and capacity
    if((st1->vC) + (st1->vB) > (st1->maxB))
    {
        st2->vC = st1->vC - (st1->maxB - st1->vB);
        st2->vB = st1->maxB; 
    }
    // otherwise C would become empty and its volume would be added to B
    else
    {
        st2->vB = st1->vB + st1->vC;
        st2->vC = 0;    
    }
    // initialize the fn_index to 0 to start from first callback funtion in the array
    st2->fn_index = 0;
    // move: 32 for transition from C to B
    st2->move = 32;
}

// perform state space search in dfs manner to reach from start state to goal state
int state_space_search(state_t* start, state_t* goal)
{
    // create a new empty list
    list_t* mylist = new_list();   
    // flag if solution is found and number of solutions
    int soln = 0, count = 0;

    // add the start state to the list
	state_t temp = *start;
	end_insertion(mylist, &temp);

    // until we donot have all the solutions i.e until the list is not empty
	while(mylist->head != NULL)
	{
        // make a transition based on the fn_index which would be incremented based on the last transition
		transition[(mylist->tail->st).fn_index](&(mylist->tail->st), &temp);
        // if the resultant state is not in the linked list and is valid
		if(is_valid(&temp) && is_unique(mylist, &temp))
		{
            // add it to the linked list
			end_insertion(mylist, &temp);
            // if it is same as goal state, print the list as we found one of the solution and increment the count for number of solutions
            if(is_equal(goal, &temp)) 
            { 
                count++;
                print_list(mylist); 
            }	
		}
        // if the resultant state is in the linked list or is not valid
		else
		{
            // until the list not empty and no more transitions can take place
			while(mylist->head!=NULL && ++((mylist->tail->st).fn_index) == 6)
			{
				// delete the state that caused non valid or repeated state and backtrack
				end_deletion(mylist);
			}
		}
	}

    // delete and free the linked list and return the number of solutions
    delete_list(mylist);
    return count;
}

// callback array with 6 transition functions in order specified
void(*transition[])(const state_t *st1, state_t *st2) = 
{ 
    A2B, A2C, B2A, B2C, C2A, C2B
};
