#ifndef ACTIONS_H
# define ACTIONS_H

#include <stack.h>

void	swapA(t_stacks* ss);
void	swapB(t_stacks* ss);
void	pushA(t_stacks* ss);
void	pushB(t_stacks* ss);
void	rotateA(t_stacks* ss);
void	rotateB(t_stacks* ss);
void	reverseA(t_stacks* ss);
void	reverseB(t_stacks* ss);
void	rr(t_stack* stack_a, t_stack* stack_b);
void	rrr(t_stack* stack_a, t_stack* stack_b);

#endif