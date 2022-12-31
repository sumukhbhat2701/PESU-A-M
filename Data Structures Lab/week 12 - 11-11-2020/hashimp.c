#include "hash.h"
HashTable *create_table(int size)
{
    //TODO
    HashTable *new_table = (HashTable *)malloc(sizeof(HashTable));
    
    new_table->table = (int *)malloc(size*sizeof(int));

    new_table->size = size;

    for(int i=0;i<size;i++)
    {
        //initialize everything to -1
        new_table->table[i] = -1;
    }

    return new_table;
}

void insert(HashTable *htable, int element)
{
    //TODO
    int pos = (element)%(htable->size);
    if(htable->table[pos] == -1)
    {
        htable->table[pos] = element;
        return;
    }
    int next_pos = pos+1;
    while(next_pos != pos && htable->table[next_pos] != -1)
    {
        next_pos = (next_pos+1)%(htable->size);
    }
    if(next_pos != pos)
    {
        htable->table[next_pos] = element;
        return;
    }
    return;
}

void delete (HashTable *htable, int element)
{
    //TODO
    int pos = (element)%(htable->size);
    if(htable->table[pos] == element)
    {
        htable->table[pos] = -1;
    }
    int next_pos = pos + 1;
    while(next_pos != pos && htable->table[next_pos] != element)
    {
        next_pos = (next_pos+1)%(htable->size);
    }
    if(next_pos != pos)
    {
        htable->table[next_pos] =-1;
    }
    return;
}

int search(HashTable *htable, int element)
{
    //TODO
    int pos = (element)%(htable->size);
    if(htable->table[pos] == element)
    {
        //found already
        return 1;
    }
    int next_pos = pos+1;
    while(next_pos != pos && htable->table[next_pos] != element)
    {
        next_pos = (next_pos+1)%(htable->size);
    }
    if(next_pos == pos){
        return 0;
    }
    else
    {
        return 1;
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
