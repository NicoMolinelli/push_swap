#include <stack.h>
#include <libft.h>

// s1 destination s2 source
void	push(t_stack* s1, t_stack* s2)
{
	if (s2->list[s2->start % s2->items])
	{
		if (!s1->start % s1->items)// case start points to first element must add new item as last position
			s1->start = s1->items - 1;
		// else if (s1->start % s1->items == (s1->items - 1)) // case start is last element 
		// 	s1->start = 0;
		else
			s1->start--;// normal case
		s1->list[s1->start % s1->items] = s2->list[s2->start % s2->items];
		ft_bzero(&s2->list[s2->start % s2->items], sizeof(int));
		// if the next item is valid point to that one
		if (s2->list[(s2->start + 1) % s2->items])
			s2->start++;
	}
}
