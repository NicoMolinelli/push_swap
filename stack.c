#include <stack.h>

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

// TODO
// void	free_stack(t_stack8 stack)

// important
void	print_stack(t_stack* stack)
{
	size_t	i;

	i = stack->start;
	while (i < stack->items + stack->start)
	{
		printf("%d\n", stack->list[i % stack->items]);
		i++;
	}
}
