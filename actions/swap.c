#include <stack.h>
#include <libft.h>

static void	swap(t_stack* st)
{
	int	temp;

	if (st->head && st->head->next)
	{
		temp = st->head->value;
		st->head->value = st->head->next->value;
		st->head->next->value = temp;
	}
}

void	swapA(t_stacks* ss)
{
	swap(ss->a);
	ss->str = ft_strjoin(ss->str, "sa\n");
		return ;// print error
}

void	swapB(t_stacks* ss)
{
	swap(ss->b);
	ss->str = ft_strjoin(ss->str, "sb\n");
		return ;// print error
}
