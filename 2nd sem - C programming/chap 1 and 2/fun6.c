#include<stdio.h> 
  int main()

// recursive function to count set bits 
int countSetBits(int n) 
{ 
    // base case 
    if (n == 0) 
        return 0; 
  
    else
  
        // if last bit set add 1 else add 0 
        return (n & 1) + countSetBits(n >> 1); 
} 
  
// driver code 
int main() 
{ 
    // get value from user 
    int n = 9; 
  
    // function calling 
     countSetBits(n);

  
    return 0; 
} 