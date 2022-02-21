#include <validate.h>

static int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

// add in libft as upper func
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_issign(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return(0);
}