/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:36 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 15:54:39 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>

static void	rev_rotate(t_stack *st)
{
	t_node	*tail;

	tail = st->tail;
	st->tail = tail->prev;
	st->tail->next = 0;
	st->head->prev = tail;
	tail->next = st->head;
	tail->prev = 0;
	st->head = tail;
}

void	reverse_a(t_stacks *ss)
{
	if (!ss->err)
	{
		rev_rotate(ss->a);
		ss->str = ft_strjoin(ss->str, "rra\n");
		if (!ss->str)
			ss->err = 1;
	}
}

void	reverse_b(t_stacks *ss)
{
	if (!ss->err)
	{
		rev_rotate(ss->b);
		ss->str = ft_strjoin(ss->str, "rrb\n");
		if (!ss->str)
			ss->err = 1;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
