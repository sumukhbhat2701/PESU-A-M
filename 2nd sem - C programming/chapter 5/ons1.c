// Unions
#include <stdio.h>
union xyz 
{
  int x;
  char y;  
  struct x1{
	  int x2;
	  float y2;
  }xx1;
};
int main()
{
 union xyz xy;
  xy.x=321;
  printf("x = %d\t y= %d",xy.x,xy.y);
  xy.y='Z';
  printf("x = %d\t y= %d",xy.x,xy.y);
}