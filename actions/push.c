#include <stack.h>
#include <stdio.h>
#include <libft.h>

// dst destination src source
static void	push(t_stack* dst, t_stack* src)
{
	t_node*	node;

	if (src->head)
	{
		node = src->head;
		src->head->prev = 0;
		src->head = src->head->next;
		node->next = 0;// check if useful
		node->prev = 0;// check if useful
		st_prepend(node, dst);
	}
}

void	pushA(t_stacks* ss)
{
	push(ss->a, ss->b);
	ss->str = ft_strjoin(ss->str, "pa\n");
		return ;// print error
}

void	pushB(t_stacks* ss)
{
	push(ss->b, ss->a);
	ss->str = ft_strjoin(ss->str, "pb\n");
		return ;// print error
}
