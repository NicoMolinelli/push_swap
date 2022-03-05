#include <stack.h>

// find and return min index in stack
static int	st_min_index(t_stack* st, int length)
{
	t_node*	i;
	int		min;
	int		count;

	count = 1;
	i = st->head->next;
	min = st->head->index;
	while (i && count < length)
	{
		if (min > i->index)
			min = i->index;
		i = i->next;
		count++;
	}
	return (min);
}

// find and return min value in stack
static int	st_max_index(t_stack* st, int length)
{
	t_node*	i;
	int		max;
	int		count;

	count = 1;
	i = st->head->next;
	max = st->head->index;
	while (i && count < length)
	{
		if (max < i->index)
			max = i->index;
		i = i->next;
		count++;
	}
	return (max);
}

// get the average number in stack st(if equal get the max)
int	get_median(t_stack* st, int length)
{
	int	min;
	int	max;
	int	gap;

	min = st_min_index(st, length);
	printf
	max = st_max_index(st, length);
	gap = (max - min) / 2;
	return (gap + min);
}
