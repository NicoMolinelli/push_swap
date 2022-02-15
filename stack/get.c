#include <stack.h>

/*
*	get the actual length of the stack st	
*/
int	st_len(t_stack* st)
{
	t_node* i;
	int		len;

	i = st->start;
	len = 0;
	while (i)
	{
		i = i->next;
		len++;
	}
	return (len);
}

/*
*	finds the first occurence of value val in stack st and returns its index
*	return -1 if no occurencies
*/
int	st_index(int val, t_stack* st)
{
	t_node*	i;
	int		index;

	i = st->start;
	index = 0;
	while (i)
	{
		if (i->value == val)
			return (index);
		i = i->next;
		index++;
	}
	return (-1);
}
