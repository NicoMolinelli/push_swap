/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:04:18 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 18:17:59 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sort.h>
#include <validate.h>

int	main(int argc, char **argv)
{
	t_stacks	*ss;

	ss = create_stacks(--argc, ++argv);
	if (!ss)
		return (0);
	sort(ss, st_len(ss->a));
	sts_clear(ss, 0);
}
