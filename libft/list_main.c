#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

void	gino(int	*p)
{
	printf("hellooooo%d\n", *p);
}

void	hi(void (*del)(int *))
{
	int	a = 4;
	(*del)(&a);
}

void	toni(void (*del)(int *))
{
	hi(del);
}

int	main ()
{
	// printf("%zu\n", sizeof(t_list));
	char a = 'b';
	int b = 4;
	void	*pa = &a;
	void	*pb = &b;
	t_list *car = ft_lstnew(pa);
	t_list *num = ft_lstnew(pb);
	car->next = num;
	num->next = 0;
	char *pot = car->content;
	int *nut = num->content;
	// printf("%c\n", *pot);
	// printf("%d\n", *nut);

	t_list *l = ft_lstnew(strdup("nyacat"));
	t_list *n = ft_lstnew(strdup("OK"));

	ft_lstadd_front(&l, n);
	if (l == n && !strcmp(l->content, "OK"))
	{
		printf("Success!\n");
	}

	t_list *f = ft_lstnew(strdup("toni"));
	ft_lstadd_front(&n, f);
	t_list *m = ft_lstnew(strdup("porca"));
	ft_lstadd_front(&f, m);
	// printf("last: %s\n", ft_lstlast(m)->content);
	t_list *k = ft_lstnew(strdup("oooo"));
	ft_lstadd_back(&m, k);
	printf("size: %d\n", ft_lstsize(m));
	printf("%s\n", ft_lstlast(m)->content);
	printf("%s\n", (*m).content);
	printf("size: %d\n", ft_lstsize(m));

	// toni(&gino);
	
	t_list *sdf = lstnew(strdup(" 1 2 3 "));
	t_list *ret;

	sdf->next = lstnew(strdup("ss"));
	sdf->next->next = lstnew(strdup("-_-"));
	printf("%s\n", ft_lstlast(sdf)->content);
	ret = ft_lstmap(l, lstmap_f, ((void *)0));
	if (!strcmp(ret->content, "OK !") && !strcmp(ret->next->content, "OK !") && !strcmp(ret->next->next->content, "OK !") && !strcmp(l->content, " 1 2 3 ") && !strcmp(l->next->content, "ss") && !strcmp(l->next->next->content, "-_-"))
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);
}
