#ifndef SORT_H
# define SORT_H

#include <stack.h>

typedef struct s_partition
{
	int	right;
	int	left;
} t_partition;

void	sort(t_stack* sta, t_stack* stb, int length);
void	select_sort(t_stack* sa, t_stack* sb);
void	quicksort(t_stack* sa, t_stack* sb, int length);
void	quicksortA(t_stack* st_a, t_stack* st_b, int length);
void	sort_2(t_stack* st);
void	sort_3(t_stack* st);
void	sort_4ab(t_stack* a, t_stack* b);

t_partition	partitionB(t_stack* st_a, t_stack* st_b, int length);
t_partition	partitionA(t_stack* st_a, t_stack* st_b, int length);

int	is_sorted(t_stack* st, int length);

#endif