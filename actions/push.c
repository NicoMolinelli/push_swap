#include <stack.h>
#include <stdio.h>

static void	print_push(int name)
{
	printf("p%c\n", name);
}

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
		print_push(dst->name);
	}
}
