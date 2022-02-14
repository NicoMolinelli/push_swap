#include <stack.h>
#include <stdio.h>

static void	rotate(t_stack* st)
{
	t_node*	start;

	start = st->start;// save the current start node
	st->start = start->next;// new stack start node becames the second node
	st->start->prev = 0;// start prev points to null
	st->end->next = start;// current end node points to "start"
	start->next = 0;
	start->prev = st->end;
	st->end = start;
}

void	ra(t_stack* stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	rb(t_stack* stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	rr(t_stack* stack_a, t_stack* stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}
