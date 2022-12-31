#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    //TODO
    tree -> root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    //TODO
	if(tree->root==NULL)
	{
		tree->root = (Node*)malloc(sizeof(Node));
		tree->root->data = data;
		tree->root->left = NULL;
		tree->root->right = NULL;
		tree->root->leftThread = 1;
		tree->root->rightThread = 1;
		return;
	}
    // traverse to the target
    Node* front = tree->root;
    Node* back = NULL; 
    while (front != NULL) { 
        back = front;
 
        if (data < front->data) {
            if (front->leftThread == 0)
                front = front->left;
            else
                break;
        }
 
         else {
            if (front->rightThread == 0)
                front = front->right;
            else
                break;
        }
    }
 
    Node* new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->leftThread = 1;
    new->rightThread = 1;
    new->left = NULL;
    new->right = NULL;

    if (data < (back->data)) {
        new->left = back->left;
        new->right = back;
        back->leftThread = 0;
        back->left = new;
    }
    else {
        new->left = back;
        new->right = back->right;
        back->rightThread = 0;
        back->right = new;
    }
}

Node *inorder_predecessor(Node *ptr)
{
   //TODO
   Node *temp = ptr;
   if (temp->leftThread == 1)
        return temp->left;
 
    temp = temp->left;
    while (temp->rightThread == 0)
        temp = temp->right;
    return temp;
}

Node *inorder_successor(Node *ptr)
{
   //TODO
	Node *temp = ptr;
    if (temp->rightThread == 1)
        return temp->right;
 
    temp = temp->right;
    while (temp->leftThread == 0)
        temp = temp->left;
    return temp;
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
	Node* ptr = tree->root;
    while (ptr->leftThread == 0)
        ptr = ptr->left;
 
    while (ptr != NULL) {
        printfun(ptr->data);
        ptr = inorder_successor(ptr);
    }
	nextline();
    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
	Node* ptr = tree->root;
    while (ptr->rightThread == 0)
        ptr = ptr->right;
 
    while (ptr != NULL) {
        printfun(ptr->data);
        ptr = inorder_predecessor(ptr);
    }
	nextline();
	
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement  
}

void destroy(Node *r)
{
    //TODO
	if(r!=NULL)
	{
        if(r->leftThread!=1)
		    destroy(r->left);
        if(r->rightThread!=1)
		    destroy(r->right);
	}
	free(r);
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}