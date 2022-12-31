#include "et.h"

void inorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
  if(root!=NULL){
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
  }
   
}

void preorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
  if(root!=NULL)
  {
    printf("%c",root->data); 
    preorder(root->left);
    preorder(root->right);  
  } 
}

void postorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root!=NULL){
  postorder(root->left);
  postorder(root->right);
  printf("%c",root->data); 
 }
}

void freeTree(Node *root)
{
  if(root!=NULL){
    freeTree(root->left);
    freeTree(root->right);
  }
  free(root);
}

void stackInsert(int *top, struct Node **s,struct Node *val)
{
	++(*top);
  s[*top] = val;
}

struct Node* peek(int *top,struct Node **s)
{
	struct Node *val = s[*top];
	(*top)--;
	return val;
}

int char_status(char key)
{
  if(key=='+' || key=='-' || key=='*' || key=='/')
    return 1;
  else
  {
    return 0;
  }
  
}

Node * createExpressionTree(char* a,int len)
{
    //TODO
    struct Node *myStack[200];
    int i=0,stackTop = -1;
    struct Node *character;
    
    while(a[i]!='\0')
    {	  
      character = (struct Node *)(malloc(sizeof(struct Node)));
      character->data = a[i];
      character->left = NULL;
      character->right = NULL;
      if(!char_status(a[i]))	
      {
        //operand
        stackInsert(&stackTop,myStack,character); 
      }	
      else 	
      {
        //operator
        character->right = peek(&stackTop,myStack);
        character->left = peek(&stackTop,myStack);
        stackInsert(&stackTop,myStack,character);
      }
      i++;
    }
    struct Node *final_expression_tree = peek(&stackTop,myStack);
    return(final_expression_tree);
}

