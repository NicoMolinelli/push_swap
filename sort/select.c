#include <stack.h>
#include <actions.h>
#include <stdio.h>

// fast way to put the node with value n as first element in stack st
void	smart_top(t_stack* st, int n)
{
	int	len;
	int	index;

	len = st_len(st);
	index = st_index(n, st);
	// normal rotate
	if (index <= len / 2)
	{
		while (index)
		{
			index--;
			rotate(st);
		}
	}
	else//reverse rotate
	{
		while (index < len)
		{
			rev_rotate(st);
			index++;
		}
	}
}

// find and return min value in stack
int	min(t_stack* st)
{
	t_node*	i;
	int		min;

	if (!st->start)
		return (-1);// stack is empty handle it
	i = st->start->next;
	min = st->start->value;
	while (i)
	{
		if (min > i->value)
			min = i->value;
		i = i->next;
	}
	return (min);
}

void	select_sort(t_stack* sa, t_stack* sb)
{
	int	m;
	
	while (sa->start)
	{
		m = min(sa);
		// printf("min: %d\n", m);
		smart_top(sa, m);
		push(sb, sa);
	}
	while (sb->start)
	{
		push(sa, sb);
	}
}
