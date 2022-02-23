#include <sort.h>
#include <validate.h>

//If no args passed print error?
int	main(int argc, char **argv)
{
	t_stack*	st_a;
	t_stack*	st_b;

	st_a = st_fill(++argv, --argc);// only integerssss
	if (!st_a || argc < 1)
		return (ft_error());
	st_b = create_stack(argc);
	if (!st_b)
		return ((int) st_clear(st_a));
	// st_print(st_a);
	sort(st_a, st_b, argc);
	st_print(st_a);

	st_clear(st_a);
	st_clear(st_b);
}
