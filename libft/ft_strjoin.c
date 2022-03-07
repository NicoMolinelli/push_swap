/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:20:51 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 16:18:06 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	n;

	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = malloc(sizeof(char) * n);
	if (!s)
	{
		if (s1)
			free(s1);
		return (0);
	}
	if (s1)
	{
		ft_strlcpy(s, s1, n);
		free(s1);
	}
	else
	{
		ft_strlcpy(s, s2, n);
		return (s);
	}
	ft_strlcat(s, s2, n);
	return (s);
}
