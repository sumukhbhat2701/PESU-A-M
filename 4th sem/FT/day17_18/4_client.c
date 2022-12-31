#include <stdio.h>
#include "4_what.h"

int main()
{
	int i;
	scanf("%d", &i);
	op[i]();
	for(i = 0; i < 4; ++i)
	{
		op[i]();
	}
}
