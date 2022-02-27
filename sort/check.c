#include <libft.h>
#include <stack.h>
#include <string.h>
#include <unistd.h>

#define p1 "ra\npb\nrra\npa\n"
#define p2 "ra"

void	pattern_check(t_stacks* ss)
{
	// char *toni = strstr(ss->str, p1);
	// ft_putstr_fd(toni, 1);
	// while(toni)
	// {
	// 	toni = strstr(toni + ft_strlen(p1), p1);
	// 	write(1, "oo\n", 3);
	// }
	// char *pino = strstr(ss->str, p1);
	// ft_putstr_fd(pino, 1);
	// while(pino)
	// {
	// 	pino = strstr(pino + ft_strlen(p1), p1);
	// 	write(1, "oo\n", 3);
	// }
	ft_putstr_fd(ss->str, 1);
	free(ss->str);
}
