#include <stack.h>
#include <validate.h>

t_stacks*	sts_clear(t_stacks* ss, int error)
{
	if (!ss)
		return (0);
	st_clear(ss->a);
	st_clear(ss->b);
	free(ss);
	if (error)
		return (ft_error());
	return (0);
}

t_stacks* create_stacks(int argc, char** argv)
{
	t_stacks* ss;

	ss = malloc(sizeof(t_stacks));
	if (!ss)
		return (ft_error());
	ss->str = 0;
	ss->a = st_fill(argv, argc, 97);// only integerssss
	if (!ss->a)
		return (sts_clear(ss, 1));
	ss->b = create_stack(argc, 98);
	if (!ss->b)
		return (sts_clear(ss, 1));
	return (ss);
}
