#include <stdio.h>
#include "state.h"

int main()
{
#if 0
	state_t s;
	set_state(&s, 3, 3, LEFT);
	disp_state(&s);
	printf("valid : %d\n", is_valid(&s));
	state_t s1; s1 = s;
	disp_state(&s1);
	state_t s2; set_state(&s2, 3, 3, RIGHT);
	printf("same : %d\n", are_same(&s, &s1));
	printf("same : %d\n", are_same(&s, &s2));
#endif
	state_t s; state_t t;
	set_state(&s, 3, 3, LEFT);
	for(int i = 0; i < 5; ++i)
	{
		move[i](&s, &t);
		disp_state(&t);
	}
	set_state(&s, 0, 0, RIGHT);
	for(int i = 0; i < 5; ++i)
	{
		move[i](&s, &t);
		disp_state(&t);
	}
	
}
