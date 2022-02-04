#include <validate.h>

static int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int	valid_input(char **argv)
{
	int	i;
	int	y;

	i = 0;
	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			if (!ft_isdigit(argv[i][y]) && !ft_issign(argv[i][y]))
				return (0);
			y++;
		}
	i++;
	}
	return (1);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return(0);
}