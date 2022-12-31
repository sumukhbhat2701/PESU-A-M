#include "hash.h"
HashTable *create_table(int size)
{
    HashTable *temp=(HashTable*)malloc(sizeof(HashTable));
    
    temp->table=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        temp->table[i]=-1;
    }
    temp->size=size;
    return temp;
}

void insert(HashTable *htable, int element)
{
    //TODO
    int index=(element)%htable->size;
    if(htable->table[index]==-1)
    {
        htable->table[index]=element;
        return;
    }
    int j=index+1;
    while(j!=index && htable->table[j]!=-1)
    {
        j=(j+1)%htable->size;
    }
    if(j==index)
        return;
    else
    {
        htable->table[j]=element;
        return;
    }
        
}

int search(HashTable *htable, int element)
{
    //TODO
    int index=(element)%htable->size;
    if(htable->table[index]==element)
    {
        return 1;
    }
    int j=index+1;
    while(j!=index && htable->table[j]!=element)
    {
        j=(j+1)%htable->size;
    }
    if(j==index)
        return 0;
    else
    {
        return 1;
    }
}

void delete (HashTable *htable, int element)
{
    //TODO
    int index=(element)%htable->size;
    if(htable->table[index]==element)
    {
        htable->table[index]=-1;
    }
    int j=index+1;
    while(j!=index && htable->table[j]!=element)
    {
        j=(j+1)%htable->size;
    }
    if(j==index)
        return;
    else
    {
        htable->table[j]=-1;;
    }

}


void destroy_table(HashTable *htable)
{
    //TODO
    for(int i=0;i<htable->size;i++)
    {
        htable->size--;
    }
    free(htable);
}
