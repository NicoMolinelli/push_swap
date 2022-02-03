#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <stack.h>
#include <unistd.h>

int	ft_issign(int c)
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

void	store_data(t_stack* stack, char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		stack->list[i] = ft_atoi(*argv++);
		i++;
	}
}

//If no args passed printf error?
int	main(int argc, char **argv)
{
	t_stack*	stack_a;
	t_stack*	stack_b;

	++argv;
	// validate input -> only unique integers
	if (!valid_input(argv) || argc < 2)
		return (ft_error());
	// initialize stacks
	stack_a = create_stack(argc - 1);
	if (!stack_a)
		return (0);
	stack_b = create_stack(argc - 1);
	if (!stack_b)
		return (0);
	// save numbers in stack_a
	store_data(stack_a, argv);
	print_stack(stack_a);
	// if (stack_b[0])
	// 	printf("hiii");
	// printf("size: %zu\n", size);
	// free stacks
	free(stack_a);
	free(stack_b);
}
