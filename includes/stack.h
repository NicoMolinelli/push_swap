#ifndef STACK_H
# define STACK_H

#include <stdlib.h>

typedef struct s_stack
{
	size_t	items;// how many items
	size_t	start;// current starting index position
	size_t	end;// current end index position
	int*	list;// array of values
}				t_stack;

t_stack*	create_stack(int items);
void	print_stack(t_stack* stack);
void	free_stack(t_stack* stack);
int	sval(t_stack* s, int offset);
int	sindex(t_stack* s, int value);

#endif