#include "heap.h"
heap* heap_construct(int n){
    heap* tmp = (heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity = n;
    tmp->size = 0;
    return(tmp);
}
void heap_destruct(heap* tmp){
    //TODO
	free(tmp);
}
int heap_get_capacity(heap* tmp){
    //TODO
    return tmp->capacity;
}
int heap_get_size(heap* tmp){
    //TODO
    return tmp->size;
}

void heap_remove(heap* tmp){
    //TODO
    int i = 0,temp,min_child,n;
	n = tmp->size;
	*(tmp->elements) = *((tmp->elements)+(n-1));
	//delete
	tmp->size -= 1;
	n = tmp->size;
	while(i<n)
	{
		min_child = i;
		if((n > 2*i+1) && ((tmp->elements)[min_child]) > ((tmp->elements)[2*i+1]))
			min_child = 2*i+1;
		if((2*i+2<n) && ((tmp->elements)[min_child]) > (tmp->elements)[2*i+2])
			min_child = 2*i+2;
		if(min_child != i)
		{
			//swap
			temp  =  (tmp->elements)[min_child];
			(tmp->elements)[min_child]  =  (tmp->elements)[i];
			(tmp->elements)[i]  =  temp;
			i = min_child;
		}
		else
			break;
	}
}

int heap_insert(heap* tmp,int data){
    //TODO
    int n,i,key,temp;	
	n = heap_get_size(tmp);
	//overflow
	if(n==heap_get_capacity(tmp))
		return 0;

	//insert
	(tmp->elements)[n] = data;
	tmp->size += 1;
	i=(tmp->size)-1;
	while(i)
	{
		//odd index
		if(i%2!=0)
		{
			//left child
			key=(i-1)/2;
			if(((tmp->elements)[i])<((tmp->elements)[key]))
			{
				//swap
				temp = (tmp->elements)[i];
				(tmp->elements)[i] = (tmp->elements)[key];
				(tmp->elements)[key] = temp;
			}
			else
				break;
		}
		//even index
		else
		{
			//right child
			key = (i-2)/2;
			if(((tmp->elements)[i])<((tmp->elements)[key]))
			{
				//swap
				temp = (tmp->elements)[i];
				(tmp->elements)[i] = (tmp->elements)[key];
				(tmp->elements)[key] = temp;
			}
			else
				break;
		}	
		i = key;
	}
	return 1;
}
int heap_get_min(heap* tmp){
    //TODO
    return *(tmp->elements);
}


