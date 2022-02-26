#include <sort.h>
#include <actions.h>

// TODO algorith to find it
// get the average number in stack st(if equal get the max)
int	get_median(t_stack* st, int length)
{
	int	min;
	int	max;
	int	 median;

	min = st_min(st, length);
	max = st_max(st, length);
	if (length == 2)
		return (max);
	median = -1;
	while (max > min)
	{
		max--;
		min++;
	}
	// printf("max: %d\tmin: %d\n", max, min);
	while (1)
	{
		median = st_index(max, st);
		if (median > -1)
			return (max);
		max++;
	}
}

// get the pivot -> move all the el less then the pivot to stb
t_partition	partitionA(t_stack* st_a, t_stack* st_b, int length)
{
	t_node* node;
	int		pivot;
	t_partition	part;

	pivot = get_median(st_a, length);
	part.right = 0;
	part.left = 0;
	node = st_a->head;
	while(length--)
	{
		if (node->value <= pivot)
		{
			push(st_b, st_a);
			part.right++;
		}
		else if (st_len(st_a) > 1)// fixxa bene
		{
			rotate(st_a);
			part.left++;
		}
		node = st_a->head;
	}
	return (part);
}

// get the pivot -> move all the el less then the pivot to stb
t_partition	partitionB(t_stack* st_a, t_stack* st_b, int length)
{
	t_node* node;
	int		pivot;
	t_partition	part;

	pivot = get_median(st_b, length);
	part.right = 0;
	part.left = 0;
	node = st_b->head;
	while(length--)
	{
		if (node->value >= pivot)
		{
			push(st_a, st_b);
			part.left++;
		}
		else
		{
			rotate(st_b);
			part.right++;
		}
		node = st_b->head;
	}
	return (part);
}
