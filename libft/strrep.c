#include <libft.h>
#include <stdlib.h>

static int	get_length(char* str, char* find, char* rep)
{
	int	length;
	int	i;
	int	find_len;
	int	rep_len;

	i = 0;
	length = 0;
	find_len = ft_strlen(find);
	rep_len = ft_strlen(rep);
	while (str[i])
	{
		if (!ft_strncmp(&str[i], find, find_len))
		{
			length += rep_len;
			i += find_len;
		}
		else
		{
			length++;
			i++;
		}
	}
	return (length);
}

char	*strrep(char* str, char* find, char* rep)
{
	char* join;
	int		i;
	int		j;
	int		tot;
	int		find_len;

	find_len = ft_strlen(find);
	if (!str || !find_len)
		return (str);
	tot = get_length(str, find, rep) + 1;
	join = malloc(sizeof(char) * tot);
	if (!join)
	{
		free(str);
		return (0);
	}
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strncmp(&str[i], find, find_len))
		{
			join[j] = 0;
			ft_strlcat(join, rep, tot);
			j += ft_strlen(rep);
			i += find_len;
		}
		else
			join[j++] = str[i++];
	}
	join[j] = 0;
	free(str);
	return (join);
}
