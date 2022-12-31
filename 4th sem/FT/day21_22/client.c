#include <stdio.h>
#include "state.h"
#include "list.h"

#define DEBUG 0
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
#if 0
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
#endif
	// create start state and goal state
	state_t start;
	state_t goal;
	set_state(&start, 3, 3, LEFT);
	set_state(&goal, 0, 0, RIGHT);
	if(DEBUG)
	{
		printf("start state : "); disp_state(&start);
		printf("goal state : "); disp_state(&goal);
	}
	int soln = 0;
	list_t mylist;
	init_list(&mylist);
	int index;
	state_t temp = start;
	add_at_end(&mylist, &temp);
	if(DEBUG)
	{
		disp_list(&mylist);
		getchar();
	}
	// while not solution
	//		make a move
	//		if valid and not repeated
	//			add to soln
	//		else
	//			try the next soln
	//			while list not empty and no more steps
	//				backtrack
	while(! soln)
	{
		// pickup the index from the last node in the list
		index = mylist.tail->st.fn_index;
		move[index](&mylist.tail->st, &temp);
		if(is_valid(&temp) && ! is_repeated(&mylist, &temp))
		{
			add_at_end(&mylist, &temp);
			soln = are_same(&goal, &temp);
			if(DEBUG)
			{
				disp_list(&mylist);
				printf("\n");
				getchar();
	
			}		
		}
		else
		{
			if(DEBUG)
			{
				printf("before incrementing index %d\n", mylist.tail->st.fn_index);
			}
			// empty list : should exit the loop
			while( ++mylist.tail->st.fn_index == 5)
			{
				// backtrack
				if(DEBUG)
				{
					printf("removing the last node\n");
					disp_state(&mylist.tail->st);
				}
				remove_at_end(&mylist);
			}
		}
	}
	disp_list(&mylist);


	
}

/*
can 3:0 mis 3:0 boat : LEFT
can 1:2 mis 3:0 boat : RIGHT
can 2:1 mis 3:0 boat : LEFT
can 0:3 mis 3:0 boat : RIGHT
can 1:2 mis 3:0 boat : LEFT
can 1:2 mis 1:2 boat : RIGHT
can 2:1 mis 2:1 boat : LEFT
can 2:1 mis 0:3 boat : RIGHT
can 3:0 mis 0:3 boat : LEFT
can 1:2 mis 0:3 boat : RIGHT
can 2:1 mis 0:3 boat : LEFT
can 0:3 mis 0:3 boat : RIGHT

*/
