#include <stack.h>
#include <stdio.h>

// dst destination src source
void	push(t_stack* dst, t_stack* src)
{
	t_node*	node;

	if (src->start)
	{
		node = src->start;
		src->start->prev = 0;
		src->start = src->start->next;
		node->next = 0;// check if useful
		node->prev = 0;// check if useful
		st_prepend(node, dst);
	}
}

void	pa(t_stack* stack_a, t_stack* stack_b)
{
	push(stack_a, stack_b);
	printf("pa\n");
}

void	pb(t_stack* stack_b, t_stack* stack_a)
{
	push(stack_b, stack_a);
	printf("pb\n");
}
