#include <stack.h>

static void	swap(t_stack* stack)
{
	int	temp;

	if (stack->list[0] && stack->list[1])
	{
		temp = stack->list[0];
		stack->list[0] = stack->list[1];
		stack->list[1] = temp;
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
