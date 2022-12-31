#include "poly.h"
#include<math.h>
#include<stdlib.h>
int exponent(int x,int y){ //to calculate x^y
	int prod=1,count=1;
	while(count<=y){
		prod = prod*x;
		count++;
	}
	return prod;

}

void insert_at_end(List *list, int data) 
{
	//TODO
    Node *new_node = (Node *)malloc(sizeof(Node));
	Node *last = list->head;
	new_node->data = data;
	new_node->link = NULL;
	if(list->head == NULL){
		list->head = new_node; 
	}
	else{
		while(last->link!=NULL){
		last = last->link;
	}
	last->link = new_node;
	}
    list->number_of_nodes+=1;
}

long long int evaluate(List *list, int x)
{
    //TODO
	long long int res=0,index=0;
	Node *temp = list->head;
	while(temp!=NULL){
		res=res+(exponent(x,index)*(temp->data));
		temp = temp->link;
		index++;
	}
	return res;


}

