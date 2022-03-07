/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:02:35 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:49:15 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <actions.h>
#include <sort.h>

static void	push_back_to_a(t_stacks *ss, int length)
{
	while (length--)
	{
		push_a(ss);
	}
}

// Sort for only two numbers
static void	sort_2b(t_stacks *ss)
{
	if (ss->b->head->value < ss->b->head->next->value)
		swap_b(ss);
}

// Remake it better
void	putp_ontop(t_stacks *ss, int name, int times)
{
	int	length;
	int	i;

	// todo names
	if (name == 'a')
		length = st_len(ss->a);
	else
		length = st_len(ss->b);
	if (length != times)
	{
		i = 0;
		if (length / 2 >= times)
		{
			while (i < times)
			{
				if (name == 'a')
					reverse_a(ss);
				else
					reverse_b(ss);
				i++;
			}
		}
		else
		{
			while (i < length - times)
			{
				if (name == 'a')
					rotate_a(ss);
				else
					rotate_b(ss);
				i++;
			}
		}
	}
}

void	quicksort_b(t_stacks *ss, int length)
{
	t_partition	part;

	if (ss->err)
		return ;
	if (length <= 1)
	{
		push_a(ss);
		return ;
	}
	if (length == 2)
	{
		sort_2b(ss);
		push_back_to_a(ss, length);
		return ;
	}
	part = partition_b(ss, length);
	putp_ontop(ss, ss->b->name, part.moved);
	quicksort_a(ss, part.left);
	quicksort_b(ss, part.right);
}

void	quicksort_a(t_stacks *ss, int length)
{
	t_partition	part;

	if (ss->err)
		return ;
	if (is_sorted(ss->a, length))
		return ;
	if (length == 2)
		return (sort_2(ss));
	part = partition_a(ss, length);
	putp_ontop(ss, ss->a->name, part.moved);
	quicksort_a(ss, part.left);
	quicksort_b(ss, part.right);
}
