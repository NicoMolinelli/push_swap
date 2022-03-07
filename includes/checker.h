/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:11 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:20:19 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stack.h>

typedef struct s_item
{
	void	(*op)(t_stacks *s);
	char	*key;
}			t_item;

#endif