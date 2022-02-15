#include <stack.h>
#include <stdio.h>

void	st_print(t_stack* s)
{
	t_node* i;

	i = s->start;
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

	i = s->end;
	while (i)
	{
		printf("%d\t", i->value);
		i = i->prev;
	}
	printf("\n");
}