/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:04:09 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 18:25:01 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <actions.h>
#include <libft.h>

int	do_op(t_stacks *ss, t_item items[OP_LEN], char* key)
{
	int	i;

	i = 0;
	while (i < OP_LEN)
	{
		if (!ft_strncmp(items[i].key, key, ft_strlen(key)))
		{
			items[i].op(ss);
			return (1);
		}
		i++;
	}
	return (0);
}

void	set_items(t_item items[OP_LEN])
{
	items[0].key = "sa\n";
	items[0].op = swap_a;
	items[1].key = "sb\n";
	items[1].op = swap_b;
	items[2].key = "ss\n";
	items[2].op = swap_s;
	items[3].key = "pa\n";
	items[3].op = push_a;
	items[4].key = "pb\n";
	items[4].op = push_b;
	items[5].key = "ra\n";
	items[5].op = rotate_a;
	items[6].key = "rb\n";
	items[6].op = rotate_b;
	items[7].key = "rr\n";
	items[7].op = rotate_r;
	items[8].key = "rra\n";
	items[8].op = reverse_a;
	items[9].key = "rrb\n";
	items[9].op = reverse_b;
	items[10].key = "rrr\n";
	items[10].op = reverse_r;
}
