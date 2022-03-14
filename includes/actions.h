/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:07 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 10:08:32 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include <stack.h>

void	swap_a(t_stacks *ss);
void	swap_b(t_stacks *ss);
void	swap_s(t_stacks *ss);
void	push_a(t_stacks *ss);
void	push_b(t_stacks *ss);
void	rotate_a(t_stacks *ss);
void	rotate_b(t_stacks *ss);
void	rotate_r(t_stacks *ss);
void	reverse_a(t_stacks *ss);
void	reverse_b(t_stacks *ss);
void	reverse_r(t_stacks *ss);

#endif