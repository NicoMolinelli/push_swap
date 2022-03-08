/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 10:44:15 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/08 17:32:04 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <unistd.h>
#include <checker.h>

int	ft_strchr_len(const char *s, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (s[i] && s[i] != chr)
		i++;
	if (s[i] != chr)
		return (0);
	return (i + 1);
}

char	*search_line(char **buff, int fd, int nlc)
{
	int		i;
	char	*line;

	if (!buff[fd])
		return ("");
	i = ft_strchr_len(buff[fd], nlc);
	if (!i)
		return ("");
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (ft_free(buff, fd, 0));
	ft_strlcpy(line, buff[fd], i + 1);
	ft_strlcpy(buff[fd], buff[fd] + i, ft_strlen(buff[fd]) + 1);
	if (!nlc || !ft_strlen(buff[fd]))
	{
		free(buff[fd]);
		buff[fd] = 0;
	}
	return (line);
}

char	*read_file(int fd, char **buff, char **next_line)
{
	char	stream[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = read(fd, stream, BUFFER_SIZE);
	while (bytes_read >= 0)
	{
		if (!bytes_read)
		{
			*next_line = search_line(buff, fd, '\0');
			if (*next_line && ft_strlen(*next_line))
				return (*next_line);
			return (0);
		}
		stream[bytes_read] = 0;
		if (!add_to_buff(buff, fd, stream))
			return (0);
		*next_line = search_line(buff, fd, '\n');
		if (!*next_line)
			return (0);
		if (ft_strlen(*next_line))
			return (*next_line);
		bytes_read = read(fd, stream, BUFFER_SIZE);
	}
	return (ft_free(buff, fd, 0));
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*next_line;

	if (!buff[fd])
		return (read_file(fd, buff, &next_line));
	next_line = search_line(buff, fd, '\n');
	if (!next_line)
		return (0);
	if (ft_strlen(next_line))
		return (next_line);
	return (read_file(fd, buff, &next_line));
}
