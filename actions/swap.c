#include <stack.h>
#include <stdio.h>

static void	swap(t_stack* st)
{
	int	temp;

	if (st->start && st->start->next)
	{
		temp = st->start->value;
		st->start->value = st->start->next->value;
		st->start->next->value = temp;
	}
}

void	sa(t_stack* stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack* stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack* stack_a, t_stack* stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
