#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	search;

	i = 0;
	str = (unsigned char *)s;
	search = (unsigned char)c;
	while (i < n)
	{
		if (*(str + i) == search)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
