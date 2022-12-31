/*
Write a program to reverse the digits of a positive number
*/

// Program for reversing the digits
#include <stdio.h>
unsigned int reverse_digits (unsigned int number)
{
    unsigned int rebmun = 0; // The reversed number
    unsigned int temp = 0; // Working storage
	
    temp = number; // Copy to working storage
    // Reverse the number stored in temp
    // The do-while loop is most appropriate here because 
    // any positive number will have at least one digit.
    do
    {
        rebmun = 10*rebmun + temp % 10; 
        // Add rightmost digit of temp to rebmun
        temp = temp/10; // and remove it from temp
    } while(temp); // Continue as long as temp is not 0
    return rebmun;
}


int main(void)
{
    unsigned int number = 0; // The number to be reversed
	
    // Read in the value to be reversed
    printf("\nEnter a positive integer: ");
    scanf(" %u", &number);
    printf("\nThe number %u reversed is %u \n", number, reverse_digits (number) );
    return 0;
}