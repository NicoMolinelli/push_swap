#include <stack.h>
#include <libft.h>

// dst destination src source
void	push(t_stack* dst, t_stack* src)
{
	t_node*	node;

	if (src->start)
	{
		node = src->start;
		src->start = node->next;
		st_prepend(node, dst);
	}
}

void	pa(t_stack* stack_a, t_stack* stack_b)
{
	push(stack_a, stack_b);
	printf("pa");
}

void	pb(t_stack* stack_b, t_stack* stack_a)
{
	push(stack_b, stack_a);
	printf("pb");
}
