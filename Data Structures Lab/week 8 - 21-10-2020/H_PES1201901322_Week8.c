#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    //TODO 
    tree = (Tree *)malloc(sizeof(Tree));
    tree -> root = NULL;
}

void tree_insert(Tree *tree, int data)
{
// TODO : Insert element to create a BST
   	Node *temp;
	  int found = 1;
    
    Node* new = (Node *)(malloc(sizeof(Node)));
    new -> left = NULL;
    new -> right = NULL;
    new -> data = data;
    
    if(tree -> root == NULL){
      tree -> root = new;
    }
    else 
    {
      temp = tree -> root;
      while(found)
      {
        if(temp -> data > data)
        // Traverse left to the temp node
        {
          if(temp -> left==NULL)
          { 
            temp->left = new;
            found = 0;
          }
          else 
            {
              temp = temp->left;
            }
        }  
        else 
        {
          if(temp->right==NULL)
          // Traverse Right to the temp node
          { 
            temp->right = new;
            found = 0;
          }
          else 
            {
              temp = temp->right;
            }
        }
      }
    }    
}
void tree_delete(Tree *tree, int element)
{
   // TODO : Delete elements from BST   
    Node *child = NULL;
    Node *forward = tree->root;
    Node *prev = NULL;
    
    // Traverse to the node that needs to be deleted
      while(forward != NULL && forward->data != element)
      {
        prev = forward;
        if(element < forward->data)
          {
            forward = forward->left;
          }
        else {
          forward = forward->right;
          }
      }
      
    if (forward == NULL)	
    {
      //No such element: Search unsuccessful
    }
    else if(forward->left==NULL)
    {
      child = forward -> right;  //has only right child
    }
    else if(forward->right==NULL){
      child = forward -> left;  //has only left child
    }
    else 
    { 
      // both childs left after deletion
      Node *inorder_successor = forward->right;
      while(inorder_successor->left != NULL)
        inorder_successor = inorder_successor -> left;
      
      inorder_successor->left = forward->left;
      child = forward -> right;
    }
      
      // attach the remaining child after deletion of parent
      if(prev == NULL)
      {
        tree -> root = child;
      }
      else if(forward = prev->left)
      {
        prev -> left = child;
      }
      else if(forward = prev -> right)
      {
        prev -> right = child;
      }
      free(forward);
}

void tree_inorder(Node *r)
{
 	//TODO :  use printf to print inorder 
  if(r!=NULL){
    tree_inorder(r->left);
    printf("%d ",r->data);
    tree_inorder(r->right);
  }
  // printf("\n");
}

void tree_preorder(Node *r)
{
    //TODO :  use printf to print preorder
    if(r!=NULL){
      printf("%d ",r->data);
      tree_preorder(r->left);
      tree_preorder(r->right);
    }
    // printf("\n");
}

void tree_postorder(Node *r)
{
    //TODO :  use printf to print postorder
    if(r!=NULL){
      tree_postorder(r->left);
      tree_postorder(r->right);
      printf("%d ",r->data);
    }
    // printf("\n");
}

void postorder(Tree *t)
{
   //TODO
   tree_postorder(t->root);
   printf("\n");
  
}

void preorder(Tree *t)
{
     //TODO
     tree_preorder(t->root);
     printf("\n");

}

void inorder(Tree *t)
{
  //TODO   
  tree_inorder(t->root);
  printf("\n");
}

void destroy(Node *r)
{
  //TODO  
  if(r==NULL){
    return;
  }
  else{
    destroy(r->left);
    destroy(r->right);
  }
  free(r);
}

void tree_destroy(Tree *t)
{ 
//TODO    
  destroy(t->root);
}
