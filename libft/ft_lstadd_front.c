#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*cp;

	cp = *lst;
	*lst = new;
	new->next = cp;
}
