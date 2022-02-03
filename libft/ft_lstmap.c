#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_el;
	t_list	*itr;

	itr = lst;
	new_lst = 0;
	if (!lst)
		return (0);
	while (itr)
	{
		new_el = ft_lstnew((*f)(itr->content));
		if (!new_el)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_el);
		itr = itr->next;
	}
	return (new_lst);
}
