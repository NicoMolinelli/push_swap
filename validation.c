/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 15:04:32 by nmolinel      #+#    #+#                 */
/*   Updated: 2022/03/07 15:17:17 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

t_stacks	*ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
