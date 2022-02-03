#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*itr;

	if (!lst)
		return (0);
	itr = lst;
	while (itr->next)
		itr = itr->next;
	return (itr);
}
