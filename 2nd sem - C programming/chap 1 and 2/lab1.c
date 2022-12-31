#include<stdio.h>
#include<math.h>
#define PI 3.142
int main(void)
{
int i;
int degree;
float x;
float sum=0;
float term;
float nume;
float deno;
printf("Enter the value of degree");
scanf("%d",&degree);
x = degree * (PI/180);
nume = x;
deno = 1;
i=2;
do
{
term = nume/deno;
nume = -nume*x*x;
deno = deno*i*(i+1);
sum=sum+term;
i=i+2;
} while (fabs(term) >= 0.00001);
printf("The sine of %d is %.3f\n", degree, sum);
printf("The sine function of %d is %.3f",degree,sin(x));
}