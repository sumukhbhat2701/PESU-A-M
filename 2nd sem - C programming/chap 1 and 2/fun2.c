Example for Function without argument and without return value
#include<stdio.h>  
void printName();  
int main ()  
{  
    printf("Hello ");  
    printName();  
}  
void printName()  
{  
    printf("world");  
}  
Example for Function without argument and with return value
#include<stdio.h>  
int sum();  
int main()  
{  
    int result;   
    printf("\nGoing to calculate the sum of two numbers:");  
    result = sum();  
    printf("%d",result);  
}  
int sum()  
{  
    int a,b;   
    printf("\nEnter two numbers");  
    scanf("%d %d",&a,&b);  
    return a+b;   
}  

#Example for Function with argument and without return value

#include<stdio.h>  
void sum(int, int);  
int main()  
{  
    int a,b,result;   
    printf("\nGoing to calculate the sum of two numbers:");  
    printf("\nEnter two numbers:");  
    scanf("%d %d",&a,&b);  
    sum(a,b);  
}  
void sum(int a, int b)  
{  
    printf("\nThe sum is %d",a+b);      
}  


