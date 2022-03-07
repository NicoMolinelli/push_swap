/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:43 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:17:04 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>

static void	swap(t_stack *st)
{
	int	temp;

	if (st->head && st->head->next)
	{
		temp = st->head->value;
		st->head->value = st->head->next->value;
		st->head->next->value = temp;
	}
}

void	swap_a(t_stacks *ss)
{
	if (!ss->err)
	{
		swap(ss->a);
		ss->str = ft_strjoin(ss->str, "sa\n");
		if (!ss->str)
			ss->err = 1;
	}
}

void	swap_b(t_stacks *ss)
{
	if (!ss->err)
	{
		swap(ss->b);
		ss->str = ft_strjoin(ss->str, "sb\n");
		if (!ss->str)
			ss->err = 1;
	}
}
