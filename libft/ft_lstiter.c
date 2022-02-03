#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*itr;

	itr = lst;
	while (itr)
	{
		(*f)(itr->content);
		itr = itr->next;
	}
}
