#include <stack.h>

// get the node in stack st with value val
static t_node*	get_node(t_stack* st, int val)
{
	t_node*	n;

	n = st->head;
	while (n)
	{
		if (n->value == val)
			return (n);
		n = n->next;
	}
	return (0);
}

// set the index in the apposite node
static void	set_index(t_stack* st, int value, int index)
{
	t_node*	n;

	n = get_node(st, value);
	n->index = index;
}

void	set_indexes(t_stack* st)
{
	int	val;
	int	len;
	int	index;

	len = st_len(st);
	val = st_min(st, len);
	index = 0;
	while (index < len)
	{
		if (st_index(val, st) > -1)
		{
			set_index(st, val, index);
			index++;
		}
		val++;
	}
}
