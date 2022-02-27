#include <actions.h>
#include <stdio.h>
#include <sort.h>

static void	push_back_toA(t_stacks* ss, int length)
{
	while (length--)
	{
		pushA(ss);
	}
}

// Sort for only two numbers
void	sort_2B(t_stacks* ss)
{
	if (ss->b->head->value < ss->b->head->next->value)
		swapB(ss);
}

//int
void	quicksortB(t_stacks* ss, int length)
{
	t_partition	part;
	int		i;

	if (length <= 1)
	{
		pushA(ss);
		return ;
	}
	if (length == 2)
	{
		sort_2B(ss);
		push_back_toA(ss, length);
		return ;
	}

	// printf("partitioB\n");
	part = partitionB(ss, length);

	// put back on top the small part
	i = 0;
	if (st_len(ss->b) != part.right)
	{
		while (i < part.right)
		{
			reverseB(ss);
			i++;
		}
	}
	quicksortA(ss, part.left);



	quicksortB(ss, part.right);
}

void	quicksortA(t_stacks* ss, int length)
{
	t_partition	part;
	int	i;

	if (is_sorted(ss->a, length))
		return ;
	if (length == 2)
	{
		sort_2(ss);
		return ;
	}
	// printf("partitioA\n");
	// printf("lengthA: %d\n", length);
	part = partitionA(ss, length);

	// push back on top
	i = 0;
	if (st_len(ss->a) != part.left)
	{
		while (i < part.left)
		{
			reverseA(ss);
			i++;
		}
	}

	quicksortA(ss, part.left);

	quicksortB(ss, part.right);
}
