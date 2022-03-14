/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:11 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 15:36:29 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 1
# define OP_LEN 11

# include <stack.h>

typedef struct s_item
{
	void	(*op)(t_stacks* s);
	char*	key;
}			t_item;

void	set_items(t_item items[OP_LEN]);
int		do_op(t_stacks *ss, t_item items[OP_LEN], char* key);

#endif