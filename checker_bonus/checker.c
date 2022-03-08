/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:04:04 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 18:22:13 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <actions.h>
#include <validate.h>
#include <get_next_line.h>
#include <libft.h>
#include <checker.h>


int	checker(t_stacks *ss, t_item items[OP_LEN])
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!do_op(ss, items, line))
		{
			free(line);
			return ((int) ft_error());
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks			*ss;
	static t_item		items[OP_LEN];

	ss = create_stacks(--argc, ++argv);
	if (!ss)
		return (0);
	set_items(items);
	if (checker(ss, items))
	{
		if (is_sorted(ss->a, st_len(ss->a)) && !ss->b->head)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	if (ss->str)
		free(ss->str);
	sts_clear(ss, 0);
	// system("leaks checker");
}
