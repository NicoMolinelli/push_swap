/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   core.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:01:29 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:52:29 by nmolinel      ########   odam.nl         */
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

/*
*	Creates the stack and fill it with all the params in argv converted to ints
*
*/
t_stack	*st_fill(char **argv, int items, int name)
{
	t_stack		*s;
	long		val;

	s = create_stack(items, name);
	if (!s)
		return (0);
	while (*argv)
	{
		val = ft_atoi(*argv);
		if (!is_number(*argv) || st_index(val, s) >= 0 || !is_int(val))
			return (st_clear(s));
		if (!st_append(create_node((int) val), s))
			return (st_clear(s));
		argv++;
	}
	set_indexes(s);
	return (s);
}

//free all the memory allocated from the stack s
t_stack	*st_clear(t_stack *s)
{
	t_node	*i;
	t_node	*temp;

	if (!s)
		return (0);
	i = s->head;
	while (i)
	{
		temp = i;
		i = i->next;
		free(temp);
	}
	free(s);
	return (0);
}
