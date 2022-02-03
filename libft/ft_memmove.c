#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			*(char *)(dst + len - 1) = *(char *)(src + len - 1);
			len--;
		}
	}
	return (dst);
}
