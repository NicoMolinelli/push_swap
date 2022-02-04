#include <stack.h>

static void	swap(t_stack* stack)
{
	int	temp;
	int	i;
	size_t	len;

	i = stack->start;
	len = stack->items;
	if (stack->list[i % len] && stack->list[(i + 1) % len])
	{
		temp = stack->list[i % len];
		stack->list[i % len] = stack->list[(i + 1) % len];
		stack->list[(i + 1) % len] = temp;
	}
}

void	sa(t_stack* stack_a)
{
	swap(stack_a);
}

void	sb(t_stack* stack_b)
{
	swap(stack_b);
}

void	ss(t_stack* stack_a, t_stack* stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
