/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:01:53 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 16:43:35 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <validate.h>

t_stacks	*sts_clear(t_stacks *ss, int error)
{
	if (!ss)
		return (0);
	st_clear(ss->a);
	st_clear(ss->b);
	free(ss);
	if (error)
		return (ft_error());
	return (0);
}

t_stacks	*create_stacks(int argc, char **argv)
{
	t_stacks	*ss;

	ss = malloc(sizeof(t_stacks));
	if (!ss)
		return (ft_error());
	ss->str = NULL;
	ss->err = 0;
	ss->a = st_fill(argv, argc, 97);
	if (!ss->a)
	{
		free(ss);
		return (ft_error());
	}
	ss->b = create_stack(argc, 98);
	if (!ss->b)
	{
		st_clear(ss->a);
		free(ss);
		return (ft_error());
	}
	return (ss);
}
