/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   core.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:01:29 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 18:25:47 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <limits.h>
#include <validate.h>

t_stack	*create_stack(int items, int name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->items = items;
	stack->name = name;
	stack->head = 0;
	stack->tail = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->prev = 0;
	new->next = 0;
	return (new);
}

static int	is_int(long n)
{
	if (n >= INT_MIN && n <= INT_MAX)
		return (1);
	return (0);
}

static t_stack	*check_input(t_stack* s, char **argv)
{
	char		**extra;
	char		**cp;
	long		val;

	extra = 0;
	extra = ft_split(*argv, ' ');
	if (!extra)
		return (st_clear(s, extra));
	cp = extra;
	while (*extra)
	{
		val = ft_atoi(*extra);
		if (!is_number(*extra) || st_index(val, s) >= 0 || !is_int(val))
			return (st_clear(s, extra));
		if (!st_append(create_node((int) val), s))
			return (st_clear(s, extra));
		extra++;
	}
	free_arr(cp);
	return (s);
}
/*
*	Creates the stack and fill it with all the params in argv converted to ints
*
*/
t_stack	*st_fill(char **argv, int items, int name)
{
	t_stack		*s;

	s = create_stack(items, name);
	if (!s)
		return (0);
	while (*argv)
	{
		if (!is_number(*argv) || !ft_strlen(*argv))
			return (st_clear(s, 0));
		if (!check_input(s, argv))
			return (0);
		argv++;
	}
	set_indexes(s);
	return (s);
}

//free all the memory allocated from the stack s
t_stack	*st_clear(t_stack *s, char **extra)
{
	t_node	*i;
	t_node	*temp;

	if (s)
	{
		i = s->head;
		while (i)
		{
			temp = i;
			i = i->next;
			free(temp);
		}
		free(s);
	}
	if (extra)
		free_arr(extra);
	return (0);
}
