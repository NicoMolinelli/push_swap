#ifndef ACTIONS_H
# define ACTIONS_H

#include <stack.h>

typedef struct s_item
{
	void	(*op)(t_stacks* s);
	char*	key;
}			t_item;

#endif