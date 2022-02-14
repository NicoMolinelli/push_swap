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
t_stack*	st_add_node(t_node* n, t_stack* st);
t_stack*	st_free(t_stack* s);
void		st_print(t_stack* s);

#endif