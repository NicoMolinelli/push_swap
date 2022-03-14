/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:02:05 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 12:15:07 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>
#include <string.h>
#include <validate.h>

#define P1 "\nra\npb\nrra\npa\n"
#define P2 "rra\nra\n"
#define P3 "rrb\nrb\n"
#define P5 "\nrb\npa\nrrb\npb\n"
#define P6 "\nrb\npa\nrrb\n"
#define P7 "\nra\npb\nrra\n"

static int	duplicates(t_stacks *ss)
{
	int	i;

	i = 6;
	while (i--)
	{
		ss->str = strrep(ss->str, P2, "");
		if (!ss->str)
			return (0);
		ss->str = strrep(ss->str, P3, "");
		if (!ss->str)
			return (0);
	}
	return (1);
}

static int	cleaner(t_stacks *ss)
{
	ss->str = strrep(ss->str, P1, "\nsa\n");
	if (!ss->str)
		return (0);
	ss->str = strrep(ss->str, P5, "\nsb\n");
	if (!ss->str)
		return (0);
	ss->str = strrep(ss->str, P6, "\nsb\npa\n");
	if (!ss->str)
		return (0);
	ss->str = strrep(ss->str, P7, "\nsa\npb\n");
	if (!ss->str)
		return (0);
	return (1);
}

void	pattern_check(t_stacks *ss)
{
	if (ss->err)
	{
		ft_error();
		return ;
	}
	else if (ss->str)
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
}
