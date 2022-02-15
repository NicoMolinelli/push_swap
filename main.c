#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <validate.h>
#include <stack.h>
#include <sort.h>
#include <actions.h>
#include <unistd.h>

//If no args passed print error?
int	main(int argc, char **argv)
{
	t_stack*	st_a;
	t_stack*	st_b;

	// validate input -> only unique integers
	st_a = st_fill(++argv, argc - 1);
	if (!st_a || argc < 2)
		return (ft_error());
	st_b = create_stack(argc - 1);
	if (!st_b)
		return (0);
	// st_print(st_a);
	select_sort(st_a, st_b);
	// st_print(st_a);

	st_clear(st_a);
	st_clear(st_b);
}
