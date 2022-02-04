#include <stack.h>

void	rotate(t_stack* stack, int reverse)
{
	if (reverse && !stack->start)
		stack->start = stack->items - 1;
	else if (reverse)
		stack->start--;
	else
		stack->start++;
}
