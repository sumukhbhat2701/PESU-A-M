#include <omp.h>
#include <stdio.h>
/*
To compile in MacOS: gcc -Xpreprocessor -fopenmp sharedmem.c -lomp -o <output_file>
To compile in Linux: gcc -fopenmp sharedmem.c -o <output_file>
*/
int main(int argc, char** argv) {
    int iam, np;
    #pragma omp parallel default(shared) private(iam, np)
    {
        np = omp_get_num_threads();
        iam = omp_get_thread_num();
        printf("Hello from thread %d out of %d\n", iam, np);
}
return 0; }