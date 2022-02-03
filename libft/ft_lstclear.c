#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_cpy;
	t_list	*itr;

	if (!*lst)
		return ;
	lst_cpy = *lst;
	itr = lst_cpy;
	while (itr)
	{
		itr = itr->next;
		ft_lstdelone(lst_cpy, del);
		lst_cpy = itr;
	}
	*lst = 0;
}
