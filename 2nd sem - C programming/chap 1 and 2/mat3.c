#include<stdio.h>
int main()
{
int a[2][3],i,j,b[2][3],c[2][3];
printf("ennter row and coloumn value\n");
for(i=0;i<2;i++)
for(j=0;j<3;j++){
scanf("%d",&a[i][j]);
}
printf("ennter row and coloumn value\n");
for(i=0;i<2;i++)
for(j=0;j<3;j++){
scanf("%d",&b[i][j]);
}
printf("enntered row and coloumn value\n");
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("enntered row and coloumn value\n");
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("%d\t",b[i][j]);
}
printf("\n");
}
for(i=0;i<2;i++){
for(j=0;j<3;j++){
c[i][j]=a[i][j]+b[i][j];
}
}
printf("sum of two matrix\n");
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("%d\t",c[i][j]);
}
printf("\n");
}
}
