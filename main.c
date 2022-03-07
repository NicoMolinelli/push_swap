#include <sort.h>
#include <validate.h>

int	main(int argc, char **argv)
{
	t_stacks*	ss;

	ss = create_stacks(--argc, ++argv);
	if (!ss)
		return (0);
	// st_print(ss->a);
	sort(ss, argc);
	// st_print(ss->a);
	sts_clear(ss, 0);
	// system("leaks push_swap");
}
