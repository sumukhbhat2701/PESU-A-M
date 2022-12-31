#include "server.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>

int *generate(unsigned long size,int seed){
    srand(seed);
    int *ptr = (int *)malloc(size*sizeof(int));
    for(unsigned long i=0;i<size;i++){
        *(ptr + i) = rand();
    }
    return ptr;
}

void print(int *a,unsigned long size){
    for(unsigned long i=0;i<size;i++){
        printf("%d ",*(a+i));
    }
    printf("\n");
}

void bubble_sort(int *a,unsigned long size){
    printf("Bubble Sort with %lu input size: \n",size);
    double time_spent = 0.0;
    int temp;
    unsigned long comparisions = 0;
    clock_t begin = clock();

    for(int j=0;j<(size-1);j++){
        for(int i=0;i<(size-j-1);i++){
            comparisions++;
            if(a[i]>a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
        
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("#Comparisions:%lu ; Time Spent:%lf\n",comparisions,time_spent);
    fileWrite("bubblesort.txt","bubblesort.csv",size,time_spent,comparisions);
}
void selection_sort(int *a,unsigned long size){
    printf("Selection Sort with %lu input size: \n",size);
    double time_spent = 0.0;
    unsigned long comparisions = 0;
    clock_t begin = clock(); 

    unsigned long i,j,min;
    int temp;
    for(i=0;i<size-1;i++){
        min = i;
        for(j=i+1;j<size;j++){
            comparisions++;
            if(a[j] < a[min]){
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("#Comparisions:%lu ; Time Spent:%lf\n",comparisions,time_spent);
    fileWrite("selectionsort.txt","selectionsort.csv",size,time_spent,comparisions);
}

unsigned long merge(int *L, int *R, int arr[], int left, int right,unsigned long comparisions){
    int size=left+right;
    int i=0,j=0,k=0;
    while(i<left && j< right){
        comparisions++;
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    if(i==left){
        for(;j<right;j++){
            arr[k]=R[j];
            k++;
        }
    }
    else{
        for(;i<left;i++){
            arr[k]=L[i];
            k++;
        }
    }
    return comparisions;

}


unsigned long MergeSort(int arr[], const int size,unsigned long comparisions){
    int left,right,k=0;
    int *L = (int *)malloc(sizeof(int)*size);
    int *R = (int *)malloc(sizeof(int)*size);
    if (size>1){
        left=floor(size/2);
        right=size-left;
        for(unsigned long i=0;i<left;i++)
            *(L+i)=*(arr+i);
        
        for(unsigned long i=left;i<size;i++){
            
            *(R + k)= *(arr + i);
            k++;
        }

        comparisions = MergeSort(L,left,comparisions);
        comparisions = MergeSort(R,right,comparisions);
        comparisions = merge(L,R,arr,left,right,comparisions);        
    }
    free(L);
    free(R);
    return comparisions;
}

void merge_sort(int *a,unsigned long size){
    printf("Merge Sort with %lu input size: \n",size);
    double time_spent = 0.0;
    unsigned long comparisions = 0;
    clock_t begin = clock();    

    comparisions = MergeSort(a,size,comparisions);
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("#Comparisions:%lu ; Time Spent:%lf\n",comparisions,time_spent);
    fileWrite("mergesort.txt","mergesort.csv",size,time_spent,comparisions);
}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

r_t partition(int *arr, int low, int high,unsigned long c) 
{ 
    int pivot = *(arr+high);  
    int i = (low - 1);   
  
    for (unsigned long j = low; j <= high- 1; j++) 
    { 
        c++;
        if (*(arr+j) < pivot) 
        { 
            i++; 
            swap(&(*(arr+i)),&(*(arr+j))); 
        } 
    } 
    swap(&(*(arr+(i+1))), &(*(arr+high))); 
    r_t x;
    x.p = (i + 1);
    x.comp = c; 
    return x;
} 

unsigned long QuickSort(int *arr, int low, int high,unsigned long c) 
{ 
    if (low < high) 
    { 
    
        r_t x = partition(arr, low, high,c);
        unsigned long pi = x.p;
        c = x.comp; 
        c = QuickSort(arr, low, pi - 1,c); 
        c = QuickSort(arr, pi + 1, high,c); 
    } 
    return c;
} 

void quick_sort(int *arr,unsigned long int size)
{
     printf("Quick sort with %lu input size: \n",size);
    double time_spent = 0.0;
    clock_t begin = clock(); 
    unsigned long comparisions = 0;

    comparisions = QuickSort(arr,0,size-1,comparisions);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("#Comparisions:%lu ; Time Spent:%lf\n",comparisions,time_spent);
    fileWrite("quicksort.txt","quicksort.csv",size,time_spent,comparisions);
}


void fileWrite(char* filename1,char* filename2,unsigned long size,double time, unsigned long comparsions){
    FILE *fptr1;
    FILE *fptr2;
    //txt file
    fptr1 = fopen(filename1, "a");
    if (fptr1 == NULL) {
        printf("Error of text file!");
    }
    else{
        fprintf(fptr1, "When input size is %lu : \nTime         : %lf seconds\nComaprisions : %lu\n\n", size, time, comparsions);
        fclose(fptr1);
    }
    //csv file
    fptr2 = fopen(filename2, "a");
    if (fptr2 == NULL) {
        printf("Error of csv file!");
    }
    else{
        fprintf(fptr2, "%lu,%lf,%lu\n", size, time, comparsions);
        fclose(fptr2);
    }
}

//heading of csv file
void csvFileInit(char* filename){
    FILE *fptr;
    fptr = fopen(filename,"a");
    if(fptr == NULL){
        printf("Error in csv init!");
    }
    fprintf(fptr,"%s,%s,%s\n","Input Size","Time taken(s)","#Comparisions");
    fclose(fptr);
}

