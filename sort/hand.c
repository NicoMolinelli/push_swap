/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hand.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:02:09 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:29:24 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sort.h>
#include <actions.h>

// Sort for only two numbers
void	sort_2(t_stacks *ss)
{
	if (ss->a->head->value > ss->a->head->next->value)
		swap_a(ss);
}

// sort 3 numbers
void	sort_3(t_stacks *ss)
{
	int	head;
	int	middle;
	int	tail;

	head = ss->a->head->value;
	middle = ss->a->head->next->value;
	tail = ss->a->tail->value;
	if (middle < head && head < tail)
		swap_a(ss);
	else if (tail < middle && middle < head)
	{
		swap_a(ss);
		reverse_a(ss);
	}
	else if (head > tail && tail > middle)
		rotate_a(ss);
	else if (head < tail && tail < middle)
	{
		swap_a(ss);
		rotate_a(ss);
	}
	else if (middle > head && head > tail)
		reverse_a(ss);
}

void	hand_sort(t_stacks *ss, int length)
{
	int	min;
	int	i;

	if (length == 1)
		return ;
	if (length == 2)
		return (sort_2(ss));
	else if (length == 3)
		return (sort_3(ss));
	else if (is_sorted(ss->a, length))
		return ;
	i = 0;
	while (length > 3)
	{
		min = st_min(ss->a, length);
		smart_top(ss, min);
		push_b(ss);
		length--;
		i++;
	}
	sort_3(ss);
	while (i--)
		push_a(ss);
	sort_2(ss);
}
