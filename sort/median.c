/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   median.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:02:20 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:30:52 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

// get the node in stack st with index valalue index
static int	get_index_val(t_stack *st, int index)
{
	t_node	*n;

	n = st->head;
	while (n)
	{
		if (n->index == index)
			return (n->value);
		n = n->next;
	}
	return (0);
}

// find and return min index in stack
static int	st_min_index(t_stack *st, int length)
{
	t_node	*i;
	int		min;
	int		count;

	count = 1;
	i = st->head->next;
	min = st->head->index;
	while (i && count < length)
	{
		if (min > i->index)
			min = i->index;
		i = i->next;
		count++;
	}
	return (min);
}

// find and return min value in stack
static int	st_max_index(t_stack *st, int length)
{
	t_node	*i;
	int		max;
	int		count;

	count = 1;
	i = st->head->next;
	max = st->head->index;
	while (i && count < length)
	{
		if (max < i->index)
			max = i->index;
		i = i->next;
		count++;
	}
	return (max);
}

// get the average number in stack st(if equal get the max)
int	get_median(t_stack *st, int length)
{
	int	min;
	int	max;
	int	gap;

	min = st_min_index(st, length);
	max = st_max_index(st, length);
	gap = (max - min) / 2;
	return (get_index_val(st, gap + min));
}
