// bkit fields
#include <stdio.h>
struct xy{
  unsigned int x:4;
  unsigned int y:6;
  unsigned int z:25;
};
int main()
{
  struct xy xyz;
  xyz.x=12;
  xyz.y=56;
  xyz.z=256;
  printf("size = %d \t x=%u \t y=%d",sizeof(xyz),xyz.x,xyz.y);
}