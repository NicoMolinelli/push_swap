/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:40 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 10:08:21 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>

/*save the current head node
new stack head node becames the second node
head prev points to null
current tail node points to "head"*/
static void	rotate(t_stack *st)
{
	t_node	*head;

	head = st->head;
	st->head = head->next;
	st->head->prev = 0;
	st->tail->next = head;
	head->next = 0;
	head->prev = st->tail;
	st->tail = head;
}

void	rotate_a(t_stacks *ss)
{
	if (!ss->err)
	{
		rotate(ss->a);
		ss->str = ft_strjoin(ss->str, "ra\n");
		if (!ss->str)
			ss->err = 1;
	}
}

void	rotate_b(t_stacks *ss)
{
	if (!ss->err)
	{
		rotate(ss->b);
		ss->str = ft_strjoin(ss->str, "rb\n");
		if (!ss->str)
			ss->err = 1;
	}
}

void	rotate_r(t_stacks *ss)
{
	rotate_a(ss);
	rotate_b(ss);
}
