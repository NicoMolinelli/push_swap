/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:02:48 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:51:19 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <actions.h>

int	is_sorted(t_stack *st, int length)
{
	t_node	*node;
	t_node	*next;
	int		i;

	if (length <= 1)
		return (1);
	node = st->head;
	next = node->next;
	i = 1;
	while (i < length && next)
	{
		if (node->value > next->value)
			return (0);
		node = next;
		next = node->next;
		i++;
	}
	if (i == length)
		return (1);
	return (0);
}

// fast way to put the node with value n as first element in stack st
void	smart_top(t_stacks *ss, int n)
{
	int	len;
	int	index;

	len = st_len(ss->a);
	index = st_index(n, ss->a);
	if (index <= len / 2)
	{
		while (index)
		{
			index--;
			rotate_a(ss);
		}
	}
	else
	{
		while (index < len)
		{
			reverse_a(ss);
			index++;
		}
	}
}
