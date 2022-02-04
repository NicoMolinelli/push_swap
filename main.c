#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <validate.h>
#include <stack.h>
#include <ops.h>
#include <unistd.h>

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

//If no args passed print error?
int	main(int argc, char **argv)
{
	t_stack*	stack_a;
	t_stack*	stack_b;

	// validate input -> only unique integers
	if (!valid_input(++argv) || argc < 2)
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
	
	// printf("test\n");
	// if (stack_a->list[1])
	// 	printf("hello\n");
	// ft_bzero(&stack_a->list[1], sizeof(int));
	// if (stack_a->list[1])
	// 	printf("nope\n");
	// print_stack(stack_a);

	// SWAP TEST
	// sa(stack_a);
	// print_stack(stack_a);

	// free stacks
	free_stack(stack_a);
	free_stack(stack_b);
	// system("leaks push_swap");
}
