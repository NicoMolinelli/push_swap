#include <stack.h>

t_stack*	st_append(t_node* n, t_stack* st)
{
	t_node*	tail;

	if (!n)
		return (0);
	tail = st->tail;
	if (!tail)
		st->head = n;
	else
		tail->next = n;
	n->prev = st->tail;
	st->tail = n;
	return (st);
}

t_stack*	st_prepend(t_node* n, t_stack* st)
{
	t_node*	head;

	if (!n)
		return (0);
	head = st->head;
	if (!head)
	{
		st->head = n;
		st->tail = n;
	}
	else
		head->prev = n;
	n->next = head;
	st->head = n;
	return (st);
}
