#include<stdio.h>
#include<stdlib.h>
#include "A3_header_PES1UG19CS519.h"
int main()
{
    int a,b,c,X,Y,Z,P,Q,R;
	
	// take inputs from stdin for volumes and capacities, create start and goal states out of them, 
	// apply state space search in dfs manner and print the solutions and number of solution on stdout.
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d %d",&X,&Y,&Z);
	scanf("%d %d %d",&P,&Q,&R);

	state_t start = new_state(a,b,c,X,Y,Z);
	state_t goal = new_state(a,b,c,P,Q,R);

	int soln = state_space_search(&start,&goal);

	printf("%d\n",soln);

    return 0;
}
