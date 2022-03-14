/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:02:44 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:50:34 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sort.h>

void	sort(t_stacks *ss, int length)
{
	if (length <= 5)
		hand_sort(ss, length);
	else if (length <= 10)
		select_sort(ss, length);
	else
		quicksort_a(ss, length);
	pattern_check(ss);
}
