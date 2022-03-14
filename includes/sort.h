/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:18 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:47:36 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <stack.h>

typedef struct s_partition
{
	int	right;
	int	left;
	int	moved;

}	t_partition;

void		sort(t_stacks *ss, int length);
void		select_sort(t_stacks *ss, int length);
void		quicksort_a(t_stacks *ss, int length);
void		sort_2(t_stacks *ss);
void		sort_3(t_stacks *ss);
void		hand_sort(t_stacks *ss, int length);

int			get_median(t_stack *st, int length);
t_partition	partition_b(t_stacks *ss, int length);
t_partition	partition_a(t_stacks *ss, int length);

int			is_sorted(t_stack *st, int length);

void		pattern_check(t_stacks *ss);

#endif