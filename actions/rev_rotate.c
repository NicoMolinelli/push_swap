#include <stack.h>
#include <stdio.h>

static void	rev_rotate(t_stack* st)
{
	t_node*	end;

	end = st->end;
	st->end = end->prev;// set new end
	st->end->next = 0;// second last becames last
	st->start->prev = end;
	end->next = st->start;
	end->prev = 0;
	st->start = end;
}

void	rra(t_stack* stack_a)
{
	rev_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_stack* stack_b)
{
	rev_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_stack* stack_a, t_stack* stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	printf("rrr\n");
}
