#include <stack.h>

t_stack*	st_append(t_node* n, t_stack* st)
{
	t_node*	end;

	if (!n)
		return (0);
	end = st->end;
	if (!end)
		st->start = n;
	else
		end->next = n;
	n->prev = st->end;
	st->end = n;
	return (st);
}

t_stack*	st_prepend(t_node* n, t_stack* st)
{
	t_node*	start;

	if (!n)
		return (0);
	start = st->start;
	if (!start)
		st->start = n;
	else
		start->prev = n;
	n->next = start;
	st->start = n;
	return (st);
}
