#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*itr;

	if (!lst)
		return (0);
	length = 1;
	itr = lst;
	while (itr->next)
	{
		length++;
		itr = itr->next;
	}
	return (length);
}
