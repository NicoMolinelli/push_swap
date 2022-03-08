/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 10:44:31 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 16:36:12 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <unistd.h>

char	*ft_free(char **buff, int fd, char *str)
{
	if (buff && buff[fd])
	{
		free(buff[fd]);
		buff[fd] = 0;
	}
	if (str)
		free(str);
	return (0);
}

char	*add_to_buff(char **buff, int fd, char *str)
{
	char	*tmp;
	size_t	src_len;
	size_t	tot_len;

	src_len = ft_strlen(str) + 1;
	if (!buff[fd])
	{
		buff[fd] = (char *) malloc(sizeof(char) * src_len);
		if (!buff[fd])
			return (0);
		ft_strlcpy(buff[fd], str, src_len);
		return (buff[fd]);
	}
	tmp = ft_strdup(buff[fd]);
	if (!tmp)
		return (ft_free(buff, fd, tmp));
	free(buff[fd]);
	tot_len = src_len + ft_strlen(tmp);
	buff[fd] = (char *) malloc(sizeof(char) * tot_len);
	if (!buff[fd])
		return (ft_free(0, 0, tmp));
	ft_strlcpy(buff[fd], tmp, tot_len);
	ft_strlcpy(buff[fd] + ft_strlen(tmp), str, tot_len);
	free(tmp);
	return (buff[fd]);
}
