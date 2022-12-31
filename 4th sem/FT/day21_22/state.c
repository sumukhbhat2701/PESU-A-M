#include <stdio.h>
#include "state.h"

void set_state(state_t *ptr_state, int can, int mis, int boatpos)
{
	ptr_state->can = can;
	ptr_state->mis = mis;
	ptr_state->boatpos = boatpos;
	ptr_state->fn_index = 0;
}

void disp_state(const state_t *ptr_state)
{
	printf("can %d:%d mis %d:%d boat : %s\n", ptr_state->can, 3 - ptr_state->can,	
		ptr_state->mis, 3 - ptr_state->mis, ptr_state->boatpos ? "RIGHT" : "LEFT");
}

int are_same(const state_t *ptr_lhs, const state_t *ptr_rhs)
{
	return ptr_lhs->can == ptr_rhs->can && 
			ptr_lhs->mis == ptr_rhs->mis && 
			ptr_lhs->boatpos == ptr_rhs->boatpos;
			
}

// 0 <= can <= 3
// 0 <= mis <= 3
int is_valid(const state_t *ptr_state)
{
	return
	(ptr_state->can >= 0 && ptr_state->can <= 3) &&
	(ptr_state->mis >= 0 && ptr_state->mis <= 3) &&
	((ptr_state->can == ptr_state->mis) || (ptr_state->mis == 3) ||
		(ptr_state->mis == 0));
		
}

// CC
void move_cc(const state_t *src, state_t *dst)
{
	if(src->boatpos == LEFT) // left to right
	{
		dst->can = src->can - 2;
	}
	else // right to left
	{
		dst->can = src->can + 2;
	}
	dst->mis = src->mis;
	dst->boatpos = ! src->boatpos;
	dst->fn_index = 0;
}

// MM
void move_mm(const state_t *src, state_t *dst)
{
	if(src->boatpos == LEFT) // left to right
	{
		dst->mis = src->mis - 2;
	}
	else // right to left
	{
		dst->mis = src->mis + 2;
	}
	dst->can = src->can;
	dst->boatpos = ! src->boatpos;
	dst->fn_index = 0;
}

// CM
void move_cm(const state_t *src, state_t *dst)
{
	if(src->boatpos == LEFT) // left to right
	{
		dst->mis = src->mis - 1;
		dst->can = src->can - 1;
	}
	else // right to left
	{
		dst->mis = src->mis + 1;
		dst->can = src->can + 1;
	}
	dst->boatpos = ! src->boatpos;
	dst->fn_index = 0;
}

// C 
void move_c(const state_t *src, state_t *dst)
{
	if(src->boatpos == LEFT) // left to right
	{
		dst->can = src->can - 1;
	}
	else // right to left
	{
		dst->can = src->can + 1;
	}
	dst->mis = src->mis;
	dst->boatpos = ! src->boatpos;
	dst->fn_index = 0;
}

//  M
void move_m(const state_t *src, state_t *dst)
{
	if(src->boatpos == LEFT) // left to right
	{
		dst->mis = src->mis - 1;
	}
	else // right to left
	{
		dst->mis = src->mis + 1;
	}
	dst->can = src->can;
	dst->boatpos = ! src->boatpos;
	dst->fn_index = 0;
}

void (*move[])(const state_t *src, state_t *dst) = {
	move_m,
	move_c,
	move_cm,
	move_mm,
	move_cc

};


