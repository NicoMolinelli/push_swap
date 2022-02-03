#include "libft.h"
#include <stdlib.h>

static int	check_sign(int n)
{
	if (n >= 0)
		return (1);
	return (-1);
}

static int	get_length(int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		itr;
	int		sign;
	int		length;

	itr = 0;
	length = get_length(n);
	a = malloc(sizeof(char) * (length + 1));
	if (!a)
		return (0);
	sign = check_sign(n);
	if (!(sign + 1))
		*a = '-';
	a[length] = 0;
	while (n || !itr)
	{
		length--;
		a[length] = n % 10 * sign + '0';
		n /= 10;
		itr++;
	}
	return (a);
}
