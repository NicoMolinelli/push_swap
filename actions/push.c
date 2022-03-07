/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:32 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:13:28 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>

// dst destination src source
static void	push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (src->head)
	{
		node = src->head;
		src->head->prev = 0;
		src->head = src->head->next;
		node->next = 0;
		node->prev = 0;
		st_prepend(node, dst);
	}
}

void	push_a(t_stacks *ss)
{
	if (!ss->err)
	{
		push(ss->a, ss->b);
		ss->str = ft_strjoin(ss->str, "pa\n");
		if (!ss->str)
			ss->err = 1;
	}
}

void	push_b(t_stacks *ss)
{
	if (!ss->err)
	{
		push(ss->b, ss->a);
		ss->str = ft_strjoin(ss->str, "pb\n");
		if (!ss->str)
			ss->err = 1;
	}
}
