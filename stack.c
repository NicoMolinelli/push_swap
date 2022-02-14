#include <stack.h>
#include <stdio.h>

t_stack*	create_stack(int items)
{
	t_stack* stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->items = items;
	stack->start = 0;
	stack->end = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->prev = 0;
	new->next = 0;
	return (new);
}

t_stack*	st_add_node(t_node* n, t_stack* st)
{
	t_node*	end;

	if (!n)
		return (0);
	end = st->end;
	if (!end)
		st->start = n;
	else
		end->next = n;
	st->end = n;
	return (st);
}

//TODO
t_stack*	st_free(t_stack* s)
{
	// todo free all stack
	free(s);
	return (0);
}

void	st_print(t_stack* s)
{
	t_node* i;

	i = s->start;
	while (i)
	{
		printf("%d\n", i->value);
		i = i->next;
	}
}
