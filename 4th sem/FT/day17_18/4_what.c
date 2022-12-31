#include <stdio.h>
#include "4_what.h"

void f1()
{
	printf("f1 called\n");
}
void f2()
{
	printf("f2 called\n");
}
void f3()
{
	printf("f3 called\n");
}
void f4()
{
	printf("f4 called\n");
}
// fn_t op[4];
// void (*op[4])();

fn_t op[] = {f1, f2, f3, f4};


