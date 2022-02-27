#ifndef SORT_H
# define SORT_H

#include <stack.h>

typedef struct s_partition
{
	int	right;
	int	left;
	int	moved;//optimizing instructions

} t_partition;

void	sort(t_stacks* ss, int length);
// void	select_sort(t_stack* sa, t_stack* sb);
void	quicksortA(t_stacks* ss, int length);
void	sort_2(t_stacks* ss);
void	sort_3(t_stacks* ss);
// void	sort_4ab(t_stack* a, t_stack* b);

t_partition	partitionB(t_stacks* ss, int length);
t_partition	partitionA(t_stacks* ss, int length);

int	is_sorted(t_stack* st, int length);


void	pattern_check(t_stacks* ss);

#endif