#include <libft.h>
#include <stack.h>
#include <string.h>
#include <unistd.h>

#define p1 "ra\npb\nrra\npa\n"
#define p2 "rra\nra\n"
#define p3 "rrb\nrb\n"
#define p6 "rb\npa\nrrb\n"
#define p7 "ra\npb\nrra\n"
#define p5 "rb\npa\nrrb\npb\n"

char	*strrep(char* str, char* find, char* rep);

void	pattern_check(t_stacks* ss)
{
	ss->str = strrep(ss->str, p1, "sa\n");
	ss->str = strrep(ss->str, p5, "sb\n");
	ss->str = strrep(ss->str, p6, "sb\npa\n");
	ss->str = strrep(ss->str, p7, "sa\npb\n");
	ss->str = strrep(ss->str, p2, "");
	ss->str = strrep(ss->str, p2, "");
	ss->str = strrep(ss->str, p2, "");
	ss->str = strrep(ss->str, p2, "");
	ss->str = strrep(ss->str, p3, "");
	ss->str = strrep(ss->str, p3, "");
	ss->str = strrep(ss->str, p3, "");
	ss->str = strrep(ss->str, p3, "");
	ft_putstr_fd(ss->str, 1);
	free(ss->str);
}
