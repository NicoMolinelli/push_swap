#include <stack.h>
#include <validate.h>

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

/*
*	Creates the stack and fill it with all the params in argv converted to ints
*
*/
t_stack*	st_fill(char **argv, int items)
{
	t_stack*	s;
	
	s = create_stack(items);
	if (!s)
		return (0);
	while (*argv)
	{
		if (!valid_input(*argv))
			return st_clear(s);
		if (!st_append(create_node(ft_atoi(*argv++)), s))
			return st_clear(s);
	}
	return (s);
}

//free all the memory allocated from the stack s
t_stack*	st_clear(t_stack* s)
{
	t_node* i;

	if (!s)
		return (0);
	i = s->start;
	while (i)
	{
		free(i);
		i = i->next;
	}
	free(s);
	return (0);
}
