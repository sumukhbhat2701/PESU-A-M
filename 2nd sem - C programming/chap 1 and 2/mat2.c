
#include <stdio.h>  
   
int main()  
{  
    int i, j;  
          
    //Initialize matrix a  
    int a[3][3] = {  
                    {1, 0, 1},  
                    {4, 5, 6},  
                    {1, 2, 3}  
                };  
      
    //Initialize matrix b  
    int b[3][3] = {  
                      {1, 1, 1},  
                      {2, 3, 1},  
                      {1, 5, 1}  
                 };  
      
    
      
    //Array sum will hold the result  
    int sum[3][3];  
      
    //Performs addition of matrices a and b. Store the result in matrix sum  
    for(int i = 0; i < 3; i++){  
        for(int j = 0; j < 3; j++){  
            sum[i][j] = a[i][j] + b[i][j];  
        }  
    }  
      
    printf("Addition of two matrices: \n");  
    for(int i = 0; i < 3; i++){  
        for(int j = 0; j < 3; j++){  
           printf("%d ", sum[i][j]);  
        }  
        printf("\n");  
    }  
   
    return 0;  
}  