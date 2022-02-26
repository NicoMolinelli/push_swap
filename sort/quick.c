#include <actions.h>
#include <stdio.h>
#include <sort.h>

static void	push_back_toA(t_stack* st_a, t_stack* st_b, int length)
{
	while (length--)
	{
		push(st_a, st_b);
	}
}

// Sort for only two numbers
void	sort_2B(t_stack* st)
{
	if (st->head->value < st->head->next->value)
		swap(st);
}

//int
void	quicksortB(t_stack* st_a, t_stack* st_b, int length)
{
	t_partition	part;
	int		i;

	printf("length aqui %d\n", length);
	if (length <= 1)
	{
		push(st_a, st_b);
		return ;
	}
	if (length == 2)
	{
		sort_2B(st_b);
		push_back_toA(st_a, st_b, length);
		return ;
	}

	printf("partitioB\n");
	part = partitionB(st_a, st_b, length);

	// put back on top the small part
	i = 0;
	if (st_len(st_b) != part.right)
	{
		while (i < part.right)
		{
			rev_rotate(st_b);
			i++;
		}
	}
	quicksortA(st_a, st_b, part.left);



	quicksortB(st_a, st_b, part.right);
}

void	quicksortA(t_stack* st_a, t_stack* st_b, int length)
{
	t_partition	part;
	int	i;

	if (is_sorted(st_a, length))
		return ;
	if (length == 2)
	{
		sort_2(st_a);
		return ;
	}
	printf("partitioA\n");
	printf("lengthA: %d\n", length);
	part = partitionA(st_a, st_b, length);

	// push back on top
	i = 0;
	if (st_len(st_a) != part.left)
	{
		while (i < part.left)
		{
			rev_rotate(st_a);
			i++;
		}
	}

	quicksortA(st_a, st_b, part.left);

	quicksortB(st_a, st_b, part.right);
}
