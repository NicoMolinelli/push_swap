#include <actions.h>
#include <libft.h>
#include <stdio.h>
/*
PUSH_SWAP TODO

- check for only integers values

- get_median algo

- improve algo with 100(stay lower 700 op)

- leaks checks

- norminette
*/

typedef struct s_item
{
	void	(*op)(t_stacks* s);
	char*	key;
}			t_item;

//https://benhoyt.com/writings/hash-table-in-c/
int	do_op(t_stacks* ss, t_item items[10], char* key)
{
	int	i;

	i = 10;
	while (i--)
	{
		if (!ft_strncmp(items[i].key, key, ft_strlen(items[i].key)))
		{
			items[i].op(ss);
			return (1);
		}
	}
	return (0);
}

int	checker(t_stacks* ss, t_item items[10])
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
			int success = do_op(ss, items, key)
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
	static t_item		items[10];

	ss = create_stacks(--argc, ++argv);
	if (!ss)
		return (0);
	// st_print(ss->a);
	set_items(items);
	// printf("%s\n", items[1].key);
	checker(ss, items);
	// st_print(ss->a);
	sts_clear(ss, 0);
	// system("leaks push_swap");
}
