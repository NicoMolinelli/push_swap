#include <sort.h>
#include <validate.h>
/*
PUSH_SWAP TODO

- check for only integers values

- get_median algo

- improve algo with 100(stay lower 700 op)

- leaks checks

- norminette
*/

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

	//https://benhoyt.com/writings/hash-table-in-c/
int	checker(t_stacks* ss)
{
	char	stream[100001];
	int		bytes;
	char	key[10];
	int		i;
	int		k;

	i = 0;
	k = 0;
	bytes = read(1, &stream, 100000);
	stream [bytes] = 0;
	while (stream[i])
	{
		if (stream[i] == '\n')
		{
			key[k] = 0;
			int success = nice_function_name(ss, table, key)
			if (!success)
				return (ft_error());
		}
		else
			key[k++] = stream[i];
		
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks*	ss;

	ss = create_stacks(--argc, ++argv);
	if (!ss)
		return (0);
	// st_print(ss->a);
	checker(ss);
	// st_print(ss->a);
	sts_clear(ss, 0);
	// system("leaks push_swap");
}
