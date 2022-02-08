#include <stack.h>
#include <stdio.h>

t_stack*	create_stack(int items)
{
	t_stack* stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->list = malloc(sizeof(int) * items);
	if (!stack->list)
	{
		free(stack);
		return (0);
	}
	stack->items = items;
	stack->start = 0;
	stack->end = items - 1;
	return (stack);
}

void	free_stack(t_stack* stack)
{
	if (stack->list)
		free(stack->list);
	free(stack);
}

// consider overflow
int	sval(t_stack* s, int offset)
{
	return (s->list[(s->start + offset) % s->items]);
}

int	sindex(t_stack* s, int value)
{
	size_t	index;

	index = s->start;
	while (index < s->items + s->start)
	{
		if (s->list[index % s->items] == value)
			return (index % s->items);
		index++;
	}
	return (-1);
}

// important
void	print_stack(t_stack* stack)
{
	size_t	i;

	i = stack->start;
	while (i < stack->items + stack->start)
	{
		if (stack->list[i % stack->items])
			printf("%d\n", stack->list[i % stack->items]);
		i++;
	}
}
