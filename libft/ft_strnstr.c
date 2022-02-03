#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)(haystack));
	i = 0;
	while (haystack[i] && i < len)
	{
		if (i + ft_strlen(needle) > len)
			return (0);
		else if (!(ft_strncmp(haystack + i, needle, ft_strlen(needle))))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
