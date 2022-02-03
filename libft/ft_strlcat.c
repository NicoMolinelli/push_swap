#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	dst_len;
	size_t	src_len;

	counter = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	if (dstsize > 0)
	{
		while (src[counter] && counter + dst_len < dstsize - 1)
		{
			dst[counter + dst_len] = src[counter];
			counter++;
		}
		dst[counter + dst_len] = 0;
	}
	return (dst_len + src_len);
}
