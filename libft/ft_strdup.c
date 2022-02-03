#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
