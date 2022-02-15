#include <ops.h>
#include <stack.h>

// Sort for only two numbers
void	sort_2(t_stack* st)
{
	if (st->start->value > st->start->next->value)
		sa(st);
}

// void	sort_3(t_stack* stack)
// {
	
// }
