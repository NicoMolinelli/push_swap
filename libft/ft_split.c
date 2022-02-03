#include "libft.h"
#include <stdlib.h>

static int	count_size(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			count++;
		s++;
	}
	return (count);
}

static int	split(char **arr, int arr_index, char const *s, char del)
{
	int	counter;
	int	split_len;

	counter = 0;
	split_len = 0;
	while (s[counter])
	{
		while (s[counter] == del)
			counter++;
		while (s[counter + split_len] != del && s[counter + split_len])
			split_len++;
		if (split_len)
		{
			arr[arr_index] = ft_substr(s, counter, split_len);
			if (!arr[arr_index])
				return (0);
			arr_index++;
		}
		counter += split_len;
		split_len = 0;
	}
	arr[arr_index] = 0;
	return (1);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (count_size(s, c) + 1));
	if (!arr)
		return (0);
	if (!split(arr, 0, s, c))
	{
		free_arr(arr);
		return (0);
	}
	return (arr);
}
