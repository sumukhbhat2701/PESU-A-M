#ifndef assignment1
#define assignment1
int* generate(unsigned long x,int seed);
void print(int *a,unsigned long x);
void bubble_sort(int *a,unsigned long x);
void selection_sort(int *a,unsigned long x);
void merge_sort(int *a,unsigned long x);
void quick_sort(int *a,unsigned long x);
void fileWrite(char* filename1,char* filename2,unsigned long size,double time,unsigned long comparsions);
void csvFileInit(char* filename);
struct returned{
    unsigned long comp;
    unsigned long p;
};
typedef struct returned r_t;

#endif


