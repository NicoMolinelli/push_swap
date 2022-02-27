#include <stack.h>
#include <stdio.h>
#include <libft.h>

static void	rotate(t_stack* st)
{
	t_node*	head;

	head = st->head;// save the current head node
	st->head = head->next;// new stack head node becames the second node
	st->head->prev = 0;// head prev points to null
	st->tail->next = head;// current tail node points to "head"
	head->next = 0;
	head->prev = st->tail;
	st->tail = head;
}

void	rotateA(t_stacks* ss)
{
	rotate(ss->a);
	ss->str = ft_strjoin(ss->str, "ra\n");
	return ;// print error
}

void	rotateB(t_stacks* ss)
{
	rotate(ss->b);
	ss->str = ft_strjoin(ss->str, "rb\n");
		return ;// print error
}

// handle rr
void	rr(t_stack* stack_a, t_stack* stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
