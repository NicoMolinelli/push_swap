#include <libft.h>
#include <stack.h>
#include <string.h>
#include <validate.h>

#define p1 "ra\npb\nrra\npa\n"
#define p2 "rra\nra\n"
#define p3 "rrb\nrb\n"
#define p6 "rb\npa\nrrb\n"
#define p7 "ra\npb\nrra\n"
#define p5 "rb\npa\nrrb\npb\n"

static int duplicates(t_stacks* ss)
{
	int	i;

	i = 6;
	while (i--)
	{
		ss->str = strrep(ss->str, p2, "");
		if (!ss->str)
			return (0);
		ss->str = strrep(ss->str, p3, "");
		if (!ss->str)
			return (0);
	}
	return (1);
}

static int cleaner(t_stacks* ss)
{
	ss->str = strrep(ss->str, p1, "sa\n");
	if (!ss->str)
		return (0);
	ss->str = strrep(ss->str, p5, "sb\n");
	if (!ss->str)
		return (0);
	ss->str = strrep(ss->str, p6, "sb\npa\n");
	if (!ss->str)
		return (0);
	ss->str = strrep(ss->str, p7, "sa\npb\n");
	if (!ss->str)
		return (0);
	return (1);
}

void	pattern_check(t_stacks* ss)
{
	if (!cleaner(ss))
	{
		ft_error();
		return ;
	}
	if (!duplicates(ss))
	{
		ft_error();
		return ;
	}
	ft_putstr_fd(ss->str, 1);
	free(ss->str);
}
