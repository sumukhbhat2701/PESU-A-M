#include <stdio.h>
int main()
{
 union regs
 {
  int ax:16
  struct reg{
    int ah:8;
	int al:8;
	}a;
 }a1;
 
 printf("Sizeof union regs is %d",sizeof(a1));
 
}