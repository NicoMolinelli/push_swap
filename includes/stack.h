#ifndef STACK_H
# define STACK_H

#include <stdlib.h>

typedef struct s_node
{
	struct s_node*	prev;
	struct s_node*	next;
	int				value;
}					t_node;

typedef struct s_stack
{
	size_t			items;// how many items
	struct s_node*	start;
	struct s_node*	end;
}					t_stack;



t_stack*	create_stack(int items);
t_node		*create_node(int value);
t_stack*	st_clear(t_stack* s);

t_stack*	st_fill(char **argv, int items);
t_stack*	st_append(t_node* n, t_stack* st);
t_stack*	st_prepend(t_node* n, t_stack* st);

int			st_len(t_stack* st);
int			st_index(int val, t_stack* st);

void		st_print(t_stack* s);
void		st_rev_print(t_stack* s);

#endif