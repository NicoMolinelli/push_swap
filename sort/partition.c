#include <sort.h>
#include <sort.h>
#include <stdio.h>
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

int	others(t_stacks* ss, int name, int pivot, int length)
{
	int 	i;
	t_node* n;

	i = 0;
	if (name == 'a')
		n = ss->a->head;
	else
		n = ss->b->head;
	while (i < length)
	{
		if (name == 'a' && n->value < pivot)
			return (1);
		if (name == 'b' && n->value >= pivot)
			return (1);
		i++;
		n = n->next;
	}
	return (0);
}

// get the pivot -> move all the el less then the pivot to stb
t_partition	partitionA(t_stacks* ss, int length)
{
	t_node* node;
	int		pivot;
	t_partition	part;

	pivot = get_median(ss->a, length);
	part.right = 0;
	part.left = 0;
	part.moved = 0;
	node = ss->a->head;
	while(length--)
	{
		if (node->value < pivot)
		{
			pushB(ss);
			part.right++;
		}
		else if (others(ss, 'a', pivot, length + 1))
		{
			rotateA(ss);
			part.left++;
			part.moved++;
		}
		else
			part.left++;
		node = ss->a->head;
		// printf("sdsa\n");
	}
	return (part);
}

// get the pivot -> move all the el less then the pivot to stb
t_partition	partitionB(t_stacks* ss, int length)
{
	t_node* node;
	int		pivot;
	t_partition	part;

	pivot = get_median(ss->b, length);
	part.right = 0;
	part.left = 0;
	part.moved = 0;
	node = ss->b->head;
	while(length--)
	{
		if (node->value >= pivot)
		{
			pushA(ss);
			part.left++;
		}
		else if (others(ss, 'b', pivot, length + 1))
		{
			rotateB(ss);
			part.right++;
			part.moved++;
		}
		else
			part.right++;
		node = ss->b->head;
	}
	return (part);
}
