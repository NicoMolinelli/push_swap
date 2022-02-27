#include <sort.h>
#include <validate.h>

//If no args passed print error?
int	main(int argc, char **argv)
{
	t_stacks*	ss;

	// ss = create_stacks(++argv, --argc);
	// if (!ss))
	// 	retu
	ss = malloc(sizeof(t_stacks));
	ss->str = 0;
	ss->a = st_fill(++argv, --argc, 97);// only integerssss
	if (!ss->a || argc < 1)
		return (ft_error());
	ss->b = create_stack(argc, 98);
	if (!ss->b)
		return ((int) st_clear(ss->b));
	// st_print(ss->a);
	sort(ss, argc);

	st_print(ss->a);

	st_clear(ss->a);
	st_clear(ss->b);
	// system("leaks push_swap");
}
