#include "server.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
    csvFileInit("mergesort.csv");
    csvFileInit("quicksort.csv");
    csvFileInit("bubblesort.csv");
    csvFileInit("selectionsort.csv");
    for(unsigned long size = 100000;size <= 1000000; size+=50000){
        for(int choice = 0;choice <= 3; choice++)
        {
            switch(choice){
                case 0:{
                    int *arr = generate(size,size - 99999);
                    selection_sort(arr,size);
                    free(arr);
                    printf("\n");
                    break;
                }
                case 1:{
                    int *arr = generate(size,size - 99999);
                    bubble_sort(arr,size);
                    free(arr);
                    printf("\n");
                    break;
                }
                case 2:{
                    int *arr = generate(size,2);
                    merge_sort(arr,size);
                    free(arr);
                    printf("\n");
                    break;
                    
                }
                case 3:{
                    int *arr = generate(size,size - 99999);
                    quick_sort(arr,size);
                    free(arr);
                    printf("\n");
                    break;
                }
            }
        }
        printf("--------------------------------------------------------------------------\n");

    }
    return 0;
}

/*
choice      sorting technique
0               selection
1               bubble
2               merge
3               quick
*/

