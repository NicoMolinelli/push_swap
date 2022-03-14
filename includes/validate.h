/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:03:25 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 17:25:44 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include <libft.h>
# include <unistd.h>
# include <stack.h>

int			is_number(char *str);
t_stacks	*ft_error(void);

#endif