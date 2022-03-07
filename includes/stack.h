/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:22 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:25:21 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	size_t			items;
	int				name;
	struct s_node	*head;
	struct s_node	*tail;
}					t_stack;

typedef struct s_stacks
{
	char		*str;
	int			err;
	t_stack		*a;
	t_stack		*b;
}					t_stacks;

t_stack		*create_stack(int items, int name);
t_node		*create_node(int value);
t_stack		*st_clear(t_stack *s);

t_stack		*st_fill(char **argv, int items, int name);
t_stack		*st_append(t_node *n, t_stack *st);
t_stack		*st_prepend(t_node *n, t_stack *st);

int			st_len(t_stack *st);
int			st_index(int val, t_stack *st);
int			st_val(int index, t_stack *st);
int			st_min(t_stack *st, int length);
int			st_max(t_stack *st, int length);

void		set_indexes(t_stack *st);

void		st_print(t_stack *s);
void		st_rev_print(t_stack *s);
void		st_print_index(t_stack *s);

int			is_sorted(t_stack *st, int length);
void		smart_top(t_stacks *ss, int n);

t_stacks	*sts_clear(t_stacks *ss, int error);
t_stacks	*create_stacks(int argc, char **argv);

#endif