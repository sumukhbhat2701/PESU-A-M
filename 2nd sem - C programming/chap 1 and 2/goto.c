#include <stdio.h>
int main()
{
   int sum=0;
   for(int i = 0; i<=10; i++){
	sum = sum+i;
	if(i==5)
{
	   goto addition;
}
	else
{
		goto subtraction;
	}
   
printf("hai");

   addition:
   printf("%d", sum);
	printf("valid");
	return sum;
	subtraction:
printf("%d", sum);
	printf("valid");
	return sum;


   return 0;
}
}