/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:02:39 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:50:15 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sort.h>
#include <actions.h>

// find and return min value in stack
int	min(t_stack *st)
{
	t_node	*i;
	int		min;

	i = st->head->next;
	min = st->head->value;
	while (i)
	{
		if (min > i->value)
			min = i->value;
		i = i->next;
	}
	return (min);
}

void	select_sort(t_stacks *ss, int length)
{
	int	m;
	int	i;

	i = 0;
	while (i < length - 2)
	{
		m = min(ss->a);
		smart_top(ss, m);
		push_b(ss);
		i++;
	}
	sort_2(ss);
	while (i--)
	{
		push_a(ss);
	}
}
