#include<stdio.h>
#include "server.h"
void add(struct complex z1,struct complex z2)
{
    if(z1.img+z2.img>=0)
    printf("Z1+Z2=%d+%di\n",z1.real+z2.real,z1.img+z2.img);
    else
    {
      printf("Z1+Z2=%d%di\n",z1.real+z2.real,z1.img+z2.img); 
    }
    
}
void sub(struct complex z1,struct complex z2)
{
    if(z1.img-z2.img>=0)
    printf("Z1-Z2=%d + %di\n",z1.real-z2.real,z1.img-z2.img);
    else
    {
        printf("Z1-Z2=%d%di\n",z1.real-z2.real,z1.img-z2.img);
    }
    
}
void mul(struct complex z1,struct complex z2)
{
    if(z1.img*z2.real+z2.img*z1.img>=0)
    printf("Z1*Z2=%d+%di\n",z1.real*z2.real-z1.img*z2.img,z2.img*z1.real+z2.real*z1.img);
    else
    {
        printf("Z1*Z2=%d%di\n",z1.real*z2.real-z1.img*z2.img,z2.img*z1.real+z2.real*z1.img);
    }
    
}
    