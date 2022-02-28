#include <sort.h>
#include <stdio.h>
#include <actions.h>

// find and return min value in stack
int	min(t_stack* st)
{
	t_node*	i;
	int		min;

	if (!st->head)
		return (-1);// stack is empty handle it
	i = st->head->next;
	min = st->head->value;
	while (i)
	{
		if (min > i->value)
			min = i->value;
		i = i->next;
	}
	return (min);
}

void	select_sort(t_stacks* ss, int length)
{
	int	m;
	int	i;
	
	i = 0;
	while (i < length - 2)
	{
		m = min(ss->a);
		printf("min: %d\n", m);
		smart_top(ss, m);
		pushB(ss);
		i++;
	}
	sort_2(ss);
	while (i--)
	{
		pushA(ss);
	}
}
