#include<stdio.h>
#include "trie.h"
int check(struct trienode *x)
{
  //TODO
  int count=0;
  for(int i=0;i<26;i++)
  {
    if(x->child[i]!=NULL) {
      count++;
    }
  }
  return count;
}

void push(struct trienode *x,int k)
{
  //TODO
  s[++top].m = x;
  s[top].index = k;
} 

struct stack pop()
{
  //TODO
  struct stack tos = s[top--];
  return tos;
}

struct trienode *getnode()
{
  //TODO
  struct trienode *new = (struct trienode *)malloc(sizeof(struct trienode));
  for(int i=0;i<26;i++){
    new -> child[i] = NULL;
  }
  new -> endofword = 0;
  return new;
}

void insert(struct trienode *root, char *key)
{
    //TODO
    struct trienode *temp = root;
    int ascii;
    // printf("%c",key[0]);
    for(int i=0;key[i]!='\0';i++)
    { 
      // converting from ascii to 0-25
      ascii = key[i]-'a';
      // printf("%c",ascii);
      if(temp->child[ascii]==NULL)
      {
        temp->child[ascii] = getnode();
      }
    temp = temp->child[ascii];
    }
    temp->endofword=1;	
}

void display(struct trienode *temp)
  {
      //TODO: 
     //Note : DO NOT USE printf() statement, use printfun() and   newline function for printing output 
    for(int i=0;i<26;i++)
    {
      if(temp->child[i] != NULL)
      {
        // converting to ascii
        word[length] = i + 97;
        length++;
        if(temp->child[i]->endofword == 1)
        {
          printnewline();
          for(int j=0;j<length;j++){
             printfun(word[j]);
          }
        }
        display(temp->child[i]);
      }
    }
    length--;
    return;
 }

  int search(struct trienode * root,char *key)
  {
  //TODO
    //printf("IN search fun!!!");
    struct trienode *temp = root;
    int ascii;	
    for(int i=0;key[i]!='\0';i++)
    { 
      // converting from ascii to 0-25
      ascii = key[i] - 'a';
	    if(temp->child[ascii] == NULL){
		    return 0;
      }
	    temp=temp->child[ascii];
    }
    if(temp->endofword == 1)
	  {    
      return 1;
    }
    return 0;
  }


 void delete_trie(struct trienode *root,char *key)
  {
    //TODO
    int ascii,checkStatus;	
    struct trienode *temp = root;
    struct stack popped;

    for(int i=0;key[i]!='\0';i++)
      { 
        // converting from ascii to 0-25
        ascii = key[i] - 'a';
        if(temp->child[ascii]!=NULL)
        {
            push(temp,ascii);
            temp = temp->child[ascii]; 
        }
        else{
          return; 
        }
      }
      temp->endofword = 0;
      push(temp,-1);
      
      while(1)
      {
        popped = pop();
        if(popped.index!=-1)
        {
            popped.m->child[popped.index] = NULL;
        }
        if(popped.m == root)
        {
          break;
        }
        checkStatus = check(popped.m);
        if((popped.m->endofword==1) || (checkStatus>=1))
        {
          break;
        }
        else {
          free(popped.m);
        }
      }
      return;
  }























































 /*void display(struct trienode *temp)
 {
   int i,j;
   for(i=0;i<26;i++)
   {
     if(temp->child[i]!=NULL)
     {
       word[length++]=i+97;
       if(temp->child[i]->endofword==1)//if word found
       {
          printf("\n");//print the word
          for(j=0;j<length;j++)
             printf("%c",word[j]);
        }
       display(temp->child[i]);
     }
    }
    length--;
    return;
 }



 struct trienode *getnode()
 {
   int i;
   struct trienode *temp;
   temp=(struct trienode*)malloc(sizeof(struct trienode));
   for(i=0;i<26;i++)
    temp->child[i]=NULL;
  temp->endofword=0;
   return temp;
 }


 void insert(struct trienode * root, char *key)
 {
   int i,index;
   struct trienode *temp;
   temp=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(temp->child[index]==NULL)
        temp->child[index]=getnode();
      temp=temp->child[index];
    }
    temp->endofword=1;
  }


 int search(struct trienode * root,char *key)
  {

  int i,index;
   struct trienode *temp;
   temp=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(temp->child[index]==NULL)
        return 0;
      temp=temp->child[index];
    }
    if(temp->endofword==1)
       return 1;
   return 0;
  }

 void delete_trie(struct trienode *root,char *key)
  {
    int i,j,index,flag;
    struct trienode* temp;
    temp=root;
    flag=1;

    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(temp->child[index]==NULL)
      {
         printf("Key not found\n");
         return;
      }
      temp=temp->child[index];
    }
      temp->endofword=0;
      return;
  }*/













 


 
 



















