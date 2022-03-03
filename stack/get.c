#include <stack.h>

/*
*	get the actual length of the stack st	
*/
int	st_len(t_stack* st)
{
	t_node* i;
	int		len;

	i = st->head;
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

	i = st->head;
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

/*
*	finds the value at index position in stack st
*	return the value found
*/
int	st_val(int index, t_stack* st)
{
	t_node*	i;
	int		count;

	if (index == 0)
		return (st->head->value);
	i = st->head;
	count = 0;
	while (count < index)
	{
		i = i->next;
		count++;
	}
	return (i->value);
}

// CLEAN!!
// find and return min value in stack
int	st_min(t_stack* st, int length)
{
	t_node*	i;
	int		min;
	int		count;

	if (!st->head)
		return (-1);// stack is empty handle it
	count = 1;
	i = st->head->next;
	min = st->head->value;
	while (i && count < length)
	{
		if (min > i->value)
			min = i->value;
		i = i->next;
		count++;
	}
	return (min);
}

// CLEAN!!
// find and return min value in stack
int	st_max(t_stack* st, int length)
{
	t_node*	i;
	int		max;
	int		count;

	if (!st->head)
		return (-1);// stack is empty handle it
	count = 1;
	i = st->head->next;
	max = st->head->value;
	while (i && count < length)
	{
		if (max < i->value)
			max = i->value;
		i = i->next;
		count++;
	}
	return (max);
}
