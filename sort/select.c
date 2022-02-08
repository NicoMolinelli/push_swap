#include <stack.h>
#include <stdio.h>
#include <ops.h>

// fast way to put the value in "index" position as first element in stack s
void	smart_top(t_stack* s, int index)
{
	// normal rotate
	if ((index % s->items) < s->items / 2)
	{
		while ((index % s->items) != (s->start % s->items))
		{
			rotate(s, 0);
		}
	}
	else//reverse rotate
	{
		while ((index % s->items) != (s->start % s->items))
		{
			rotate(s, 1);
		}
	}
}

// find min value in stack and return the index
int	min(t_stack* s)
{
	int		min;
	size_t	i;

	i = 1;
	min = sval(s, 0);
	while (s->list[(s->start + i) % s->items] && i < s->items)
	{
		if (min > sval(s, i))
			min = sval(s, i);
		i++;
	}
	return (sindex(s, min));
}

void	select_sort(t_stack* sa, t_stack* sb)
{
	int m;

	while (sa->list[sa->start % sa->items])
	{
		// printf("val: %d\n", sa->list[sa->start % sa->items]);
		// printf("sa di start: %zu\n", sa->start);
		m = min(sa);
		// printf("min: %d\n", m);
		smart_top(sa, m);
		push(sb, sa);
		// printf("stack a\n");
		// print_stack(sa);
		// printf("stack b\n");
		// print_stack(sb);
	}
	while (sb->list[sb->start % sb->items])
	{
		push(sa, sb);
	}
}
