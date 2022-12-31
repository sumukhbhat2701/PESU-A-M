#include <stdio.h>
#include "list.h"

int main()
{
	list_t mylist;
	init_list(&mylist);
	int a[] = {20, 40, 30, 50, 10};
	int n = 5;
	for(int i = 0; i < n; ++i)
	{
		insert_list(&mylist, a[i]);
	}
	disp_list(&mylist);
}
