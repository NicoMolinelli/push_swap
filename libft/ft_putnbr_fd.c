#include "libft.h"

static int	check_sign(int n)
{
	if (n >= 0)
		return (1);
	return (-1);
}

static int	get_length(int n)
{
	int	len;

	if (n == 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	pow_10(int exp)
{
	int	tot;

	tot = 1;
	while (exp)
	{
		tot *= 10;
		exp--;
	}
	return (tot);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	int		length;

	length = get_length(n);
	sign = check_sign(n);
	if (!(sign + 1))
		ft_putchar_fd('-', fd);
	while (length)
	{
		ft_putchar_fd(n / pow_10(length - 1) * sign + '0', fd);
		n %= pow_10(length - 1);
		length--;
	}
}
