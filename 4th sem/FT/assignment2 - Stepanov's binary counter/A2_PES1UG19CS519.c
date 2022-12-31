#include<stdio.h>
#include<stdlib.h>
#include "assignment_2.h"
#include<math.h>

//a typical node structure of a linked list with 1 data and 1 link field
struct node{
    int weight;
    struct node* link;    
};
typedef struct node node_t;

//singly linked list consisting of n-nodes. head points to the 1st node of the linked list and occupied keeps count of the 
//number of nodes in the linked list
struct sllist{
    int occupied;
    node_t* head;
};
typedef struct sllist list_t;

//initialize a array of pointers to NULL
static void init(list_t* L,const int size){
    for(int i=0;i<size;i++){
        (L+i)->occupied = 0;
        (L+i)->head = NULL;
    }
}

//analogous to end insertion in a singly linked list
static void enter(list_t* list,int data){
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new->weight = data;
    new->link = NULL;
    if(list->head == NULL){
        list->head = new;
    }
    else{
        node_t *temp;
        for(temp = list->head;temp->link!=NULL;temp = temp->link);
        temp->link = new;
    }
    list->occupied++;
}

//delete all the nodes of the list  
static void eliminate(list_t* list){
        node_t *p1 = list->head;
        node_t *p2 = NULL;
        while(p1!=NULL)
        {
            p2 = p1;
            p1 = p1->link;
            free(p2);
        }
        list->head = NULL;
        list->occupied = 0;
}

//display LHS of the required printing format i.e the 2 sets among which a match(comparision) is played
static void displaySet(node_t* set1,node_t* set2){
    node_t* p1 = set1,*p2 = set2;
    while(p1!=set2 && p1!=NULL){
        printf("%d ",p1->weight);
        p1 = p1->link;
    }
    printf("X ");
    while(p2!=NULL){
        printf("%d ",p2->weight);
        p2 = p2->link;
    }
    printf("= ");
}

//play a match(comparision) between 2 players(numbers) if 2 sets of nodes are available to compare in ith index
static void play(list_t* list,int size){
    for(int i=0;i<size;i++){ 
        //Whenever we have 2*(i+1) nodes in a linked list, that means we have 2 sets to play a match
        if(((list+i)->occupied) >= ((i+1)*2)){ 
            node_t* player1 = (list+i)->head;
            node_t* player2 = (list+i)->head;
            for(int j=0;j<(i+1);j++){
                player2 = player2->link;
            }
            displaySet(player1,player2);
            //After finding the winner, the head of the winnner advances to the next position of the array, followed by the head of the loser 
            //and followed by the other nodes of the winner set. After moving, we delete the entire linked list where the match was played. 
            if(player1->weight > player2->weight){
                enter((list+i+1),player1->weight);
                printf("%d ",player1->weight);
                enter((list+i+1),player2->weight);
                printf("%d ",player2->weight);
                node_t *temp = player1->link;
                while(temp!=player2){
                    enter((list+i+1),temp->weight);
                    printf("%d ",temp->weight);
                    temp = temp->link;
                }
                eliminate(list+i);
            }
            else{
                enter((list+i+1),player2->weight);
                printf("%d ",player2->weight);
                enter((list+i+1),player1->weight);
                printf("%d ",player1->weight);
                node_t *temp = player2->link;
                while(temp!=NULL){
                    enter((list+i+1),temp->weight);
                    printf("%d ",temp->weight);
                    temp = temp->link;
                }
                eliminate(list+i);
            }
            printf("\n");
        }
    }
}

void find_second_greatest(int *numbers, int length){
        //an array of pointers to the head of singly linked lists of size = ceil(log2(length))+1
        const int size = ceil(log2(length))+1;
        list_t *tournement = (list_t *)malloc(size*sizeof(list_t));
        
        //initialize each index to NULL
        init(tournement,size);
        
        //insert the numbers in the array of pointers at index 0 and invoke play function within which a match is played whenever we have 2 sets of 
        //nodes to play a match
        for(int i=0;i<length;i++){
            enter(tournement,numbers[i]);
            play(tournement,size);           
        }

        //Until this point, if length is a power of the 2, all matches would have been already played

        //For length which is a non-power of 2, we iterate through the array find the first 2 available sets of nodes at different indices in a sequental
        //order and play a match between them, then the a match between the winner and next available set of nodes on continuing the iteration and so on...  
        node_t *p1 = NULL,*p2 = NULL,*temp;
        int i,j,backup;
        //p1 holds the head of the linked list which is set1 and p2 is the head of p1's immediate non empty linked list which acts like set2. So p1 is always behind p2
        //i index corresponds to p1 and j index corresponds to p2
        for(i=0;i<size-1;i++){
            if((tournement+i)->occupied != 0){
                p1 = (tournement+i)->head;
                break;
            }
        }
        //A match between p1 and p2, 
        //CASE 1: if p2 wins, we insert p1->head to the 2nd position of the linked list pointed by p2(position insertion) 
        //CASE 2: if p1 wins, we keep a backup of p2->head, delete the linked list whose head is p2, insert p1,backup(p2) and rest of p1 to next index
        //swap i,j and p1,p2 and move forward until the point there is only one linked list at poition size-2 
        for(j=i+1;j<size;j++){
            if((tournement+j)->occupied != 0){
                p2 = (tournement+j)->head;
                displaySet(p2,p1);
                //CASE1...
                if(p1->weight < p2->weight){
                    node_t *new = (node_t *)malloc(sizeof(node_t));
                    new->weight = p1->weight;
                    new->link = p2->link;
                    p2->link = new;
                    for(temp = (tournement+j)->head;temp!=NULL;temp=temp->link){
                        printf("%d ",temp->weight);
                    }
                    eliminate(tournement+i);
                    i = j;
                    p1 = (tournement+j)->head;
                }
                //CASE2...
                else{
                    backup = p2->weight;
                    eliminate((tournement+j));
                    enter((tournement+j),p1->weight);
                    enter((tournement+j),backup);
                    for(temp = p1->link;temp!=NULL;temp=temp->link){
                        enter((tournement+j),temp->weight);
                    }
                    for(temp = (tournement+j)->head;temp!=NULL;temp=temp->link){
                        printf("%d ",temp->weight);
                    }
                    eliminate(tournement+i);
                    i = j;
                    p1 = (tournement+j)->head;
                }
                printf("\n");
            }
        }
        
        //We make sure that all the remaining nodes are in size-1(last) index
        for(temp=(tournement+size-2)->head;temp!=NULL;temp=temp->link){
            enter(tournement+size-1,temp->weight);
        }
        eliminate(tournement+size-2);

        //Find the 2nd max out of the logn nodes below the max of head node which is max
        int max = (tournement+size-1)->head->link->weight;
        for(temp=(tournement+size-1)->head->link->link;temp!=NULL;temp=temp->link){
            if(max < temp->weight){
                max = temp->weight;
            }
        }
        printf("\n%d\n",max);

        eliminate(tournement+size-1);
        free(tournement);
}   