#include <stack.h>
#include <stdio.h>

static void	print_swap(int name)
{
	printf("s%c\n", name);
}

void	swap(t_stack* st)
{
	int	temp;

	if (st->start && st->start->next)
	{
		temp = st->start->value;
		st->start->value = st->start->next->value;
		st->start->next->value = temp;
		print_swap(st->name);
	}
}

void	ss(t_stack* stack_a, t_stack* stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
