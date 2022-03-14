/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   partition.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:02:30 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:46:39 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sort.h>
#include <actions.h>

int	others(t_stacks *ss, int name, int pivot, int length)
{
	int		i;
	t_node	*n;

	i = 0;
	if (name == 'a')
		n = ss->a->head;
	else
		n = ss->b->head;
	while (i < length)
	{
		if (name == 'a' && n->value < pivot)
			return (1);
		if (name == 'b' && n->value >= pivot)
			return (1);
		i++;
		n = n->next;
	}
	return (0);
}

// get the pivot -> move all the el less then the pivot to stb
t_partition	partition_a(t_stacks *ss, int length)
{
	t_node		*node;
	int			pivot;
	t_partition	part;

	pivot = get_median(ss->a, length);
	part.right = 0;
	part.left = 0;
	part.moved = 0;
	node = ss->a->head;
	while (length--)
	{
		if (node->value < pivot)
		{
			push_b(ss);
			part.right++;
		}
		else if (others(ss, 'a', pivot, length + 1))
		{
			rotate_a(ss);
			part.left++;
			part.moved++;
		}
		else
			part.left++;
		node = ss->a->head;
	}
	return (part);
}

// get the pivot -> move all the el less then the pivot to stb
t_partition	partition_b(t_stacks *ss, int length)
{
	t_node		*node;
	int			pivot;
	t_partition	part;

	pivot = get_median(ss->b, length);
	part.right = 0;
	part.left = 0;
	part.moved = 0;
	node = ss->b->head;
	while (length--)
	{
		if (node->value >= pivot)
		{
			push_a(ss);
			part.left++;
		}
		else if (others(ss, 'b', pivot, length + 1))
		{
			rotate_b(ss);
			part.right++;
			part.moved++;
		}
		else
			part.right++;
		node = ss->b->head;
	}
	return (part);
}
