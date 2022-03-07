/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:07 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 15:20:42 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include <stack.h>

void	swap_a(t_stacks *ss);
void	swap_b(t_stacks *ss);
void	push_a(t_stacks *ss);
void	push_b(t_stacks *ss);
void	rotate_a(t_stacks *ss);
void	rotate_b(t_stacks *ss);
void	reverse_a(t_stacks *ss);
void	reverse_b(t_stacks *ss);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif