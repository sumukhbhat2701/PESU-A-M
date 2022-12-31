#include<stdio.h>
int main()
{
   int i, j, a[10][10], b[10][10], sum[10][10];

   printf("Enter the number of rows ");
   for(i=0;i<10;i++)
	for(j=0;j<10;j++){
	printf("%d",&a[i][j]);
}
printf("Enter the number of rows ");
   for(i=0;i<10;i++)
	for(j=0;j<10;j++){
	printf("%d",&b[i][j]);
}
for(i=0;i<10;i++)
	for(j=0;j<10;j++){
sum[i][j]=a[i][j]+b[i][j];
}
printf("\nSum of two matrices: \n");
    for (i = 0; i < 10; ++i)
        for (j = 0; j < 10; ++j) {
            printf("%d   ", sum[i][j]);
            
            }
        
    return 0;
}


