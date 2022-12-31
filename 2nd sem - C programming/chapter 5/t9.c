#include <stdio.h>
#include "t9.h"
int main()
{
  int u = 10;
  int v = inc(u++);
  printf("u = %d \t v = %d",u,v);
}