#include <actions.h>
#include <stdio.h>
#include <sort.h>

// TODO algorith to find it
// get the average number in stack st(if equal get the max)
int	get_median(t_stack* st, int length)
{
	int	min;
	int	max;
	int	 median;

	min = st_min(st, length);
	max = st_max(st, length);
	// printf("min: %d\n", min);
	// printf("max: %d\n", max);
	if (length == 2)
		return (max);
	// if (st->start->value == min)//|| st->start->value == max caso in cui primo max e poi min sei spacciato!
	// 	return (st->start->next->value);
	// return (st->start->value);
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

static int	is_sorted(t_stack* st, int length)
{
	t_node* node;
	t_node* next;
	int		i;

	if (length <= 1)
		return (1);
	node = st->start;
	next = node->next;
	i = 1;
	while (i < length && next)
	{
		if (node->value > next->value)
			return (0);
		node = next;
		next = node->next;
		i++;
	}
	if (i == length)
		return (1);
	return (0);
}

// get the pivot -> move all the el less then the pivot to stb
void	partition(t_stack* st_a, t_stack* st_b, int length)
{
	t_node* node;
	int		pivot;
	int		i;

	// printf("length: %d\n", length);
	pivot = get_median(st_a, length);
	// printf("pivot/median: %d\n", pivot);
	i = 0;
	node = st_a->start;
	while(i < length)
	{
		if (node->value < pivot)
			pb(st_b, st_a);
		else
			ra(st_a);
		node = st_a->start;
		i++;
	}
	// st_print(st_a);
	// st_print(st_b);
}

void	quicksort(t_stack* st_a, t_stack* st_b, int length)
{
	int		minor_than_pivot_count;
	int		i;

	// if (is_sorted(st_a, length))
	// 	return ;
	if (is_sorted(st_a, length))
		return ;
	if (length == 2)
	{
		sort_2(st_a);
		return ;
	}
	else if (length == 3)
	{
		sort_3(st_a);
		return ;
	}
	// split list (partition)
	partition(st_a, st_b, length);
	minor_than_pivot_count = st_len(st_b);

	//reverse the list back to original position
		i = 0;
	if (st_len(st_a) != (length - minor_than_pivot_count))
	{
		while (i < (length - minor_than_pivot_count))// optimize the rotation!
		{
			rra(st_a);
			i++;
		}
	}
	// push back on top smaller half
	while (st_b->start)
	{
		pa(st_a, st_b);
	}

	// printf("Before leftR: length=>%d left->%d right->%d\n", length, top, bottom);
	//first recursion on the smaller half
	quicksort(st_a, st_b, minor_than_pivot_count);
	
	// printf("After leftR: length=>%d left->%d right->%d\n", length, top, bottom);
	// // put on top the right part
	// if (length != st_len(st_a))
	// {
		i = 0;
		while (i < minor_than_pivot_count)// optimize the rotation!
		{
			ra(st_a);
			i++;
		}
	// }
	
	// printf("Before rightR: length=>%d left->%d right->%d\n", length, top, bottom);
	// //recursion for the right part
	quicksort(st_a, st_b, (length - minor_than_pivot_count));

	// printf("After rightR: length=>%d left->%d right->%d\n", length, top, bottom);

	// rotate list back to original position
	i = 0;
	while (i < minor_than_pivot_count)
	{
		rra(st_a);
		i++;
	}
}
