#ifndef ACTIONS_H
# define ACTIONS_H

#include <stack.h>

void	swap(t_stack* st);
void	ss(t_stack* stack_a, t_stack* stack_b);
void	push(t_stack* dst, t_stack* src);
void	rotate(t_stack* st);
void	rr(t_stack* stack_a, t_stack* stack_b);
void	rev_rotate(t_stack* st);
void	rrr(t_stack* stack_a, t_stack* stack_b);

#endif