#include <stack.h>
#include <libft.h>

static void	rev_rotate(t_stack* st)
{
	t_node*	tail;

	tail = st->tail;
	st->tail = tail->prev;// set new tail
	st->tail->next = 0;// second last becames last
	st->head->prev = tail;
	tail->next = st->head;
	tail->prev = 0;
	st->head = tail;
}

void	reverseA(t_stacks* ss)
{
	rev_rotate(ss->a);
	ss->str = ft_strjoin(ss->str, "rra\n");
		return ;// print error
}

void	reverseB(t_stacks* ss)
{
	rev_rotate(ss->b);
	ss->str = ft_strjoin(ss->str, "rrb\n");
		return ;// print error
}

void	rrr(t_stack* stack_a, t_stack* stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
