/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:01:48 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 15:01:49 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <stdio.h>

void	st_print(t_stack* s)
{
	t_node* i;

	i = s->head;
	while (i)
	{
		printf("%d\t", i->value);
		i = i->next;
	}
	printf("\n");
}

void	st_rev_print(t_stack* s)
{
	t_node* i;

	i = s->tail;
	while (i)
	{
		printf("%d\t", i->value);
		i = i->prev;
	}
	printf("\n");
}

void	st_print_index(t_stack* s)
{
	t_node* i;

	i = s->head;
	while (i)
	{
		printf("%d\t", i->index);
		i = i->next;
	}
	printf("\n");
}
