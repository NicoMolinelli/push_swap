/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 10:43:38 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 16:36:23 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <libft.h>

char	*ft_free(char **buff, int fd, char *str);
char	*get_next_line(int fd);
char	*add_to_buff(char **buff, int fd, char *str);

#endif