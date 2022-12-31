#ifndef STATE_H
#define STATE_H
#define LEFT 0
#define RIGHT 1
struct state
{
	int can; // # of cannibals on left bank
	int mis; // # of missioneries on left bank
	int boatpos; // 0 : left; 1 : right
};
typedef struct state state_t;
void set_state(state_t *ptr_state, int can, int mis, int boatpos);
void disp_state(const state_t *ptr_state);
int are_same(const state_t *ptr_lhs, const state_t *ptr_rhs);
int is_valid(const state_t *ptr_state);

void move_cc(const state_t *src, state_t *dst);
void move_mm(const state_t *src, state_t *dst);
void move_cm(const state_t *src, state_t *dst);
void move_c(const state_t *src, state_t *dst);
void move_m(const state_t *src, state_t *dst);

extern void (*move[])(const state_t *src, state_t *dst);
#endif

