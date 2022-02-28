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

void	putp_ontop(t_stacks* ss, int name, int times)
{
	int	length;
	int	i;

	// todo names
	if (name == 'a')
		length = st_len(ss->a);
	else
		length = st_len(ss->b);
	i = 0;
	if (length != times)
	{
		while (i < times)
		{
			if (name == 'a')
				reverseA(ss);
			else
				reverseB(ss);
			i++;
		}
	}
}

//int
void	quicksortB(t_stacks* ss, int length)
{
	t_partition	part;

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
	// printf("lengthB: %d\tmoved: %d\t right: %d\tleft: %d\n", length, part.moved, part.right, part.left);
	// put back on top the small part
	putp_ontop(ss, ss->b->name, part.moved);
	// left rec
	quicksortA(ss, part.left);
	// right rec
	quicksortB(ss, part.right);
}

void	quicksortA(t_stacks* ss, int length)
{
	t_partition	part;

	if (is_sorted(ss->a, length))
		return ;
	if (length == 2)
		return (sort_2(ss));
	// if (length <= 10)
	// 	return (select_sort(ss, length));
	// printf("partitioA\n");
	// printf("lengthA: %d\n", length);
	part = partitionA(ss, length);

	// push back on top
	putp_ontop(ss, ss->a->name, part.moved);

	quicksortA(ss, part.left);

	quicksortB(ss, part.right);
}
