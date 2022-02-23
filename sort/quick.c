#include <actions.h>
#include <stdio.h>
#include <sort.h>

// find and return min value in stack
static int	get_min(t_stack* st, int length)
{
	t_node*	i;
	int		min;
	int		count;

	if (!st->start)
		return (-1);// stack is empty handle it
	count = 0;
	i = st->start->next;
	min = st->start->value;
	while (i && count < length)
	{
		if (min > i->value)
			min = i->value;
		i = i->next;
		count++;
	}
	return (min);
}

// find and return min value in stack
int	get_max(t_stack* st, int length)
{
	t_node*	i;
	int		max;
	int		count;

	if (!st->start)
		return (-1);// stack is empty handle it
	count = 0;
	i = st->start->next;
	max = st->start->value;
	while (i && count < length)
	{
		if (max < i->value)
			max = i->value;
		i = i->next;
		count++;
	}
	return (max);
}

// get the average number in stack st(if equal get the max)
int	get_median(t_stack* st, int length)
{
	int	min;
	int	max;
	int	 median;

	min = get_min(st, length);
	max = get_max(st, length);
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

void	quicksort(t_stack* st_a, t_stack* st_b, int length)
{
	int		left_part_count;
	int		pivot;
	t_node* node;
	int		i;

	// if (length == 2)
	// 	return (sort_2(st_a, st_b));
	if (length <= 1)// add is sorted function
		return ;
	// pivot = get_median(st_a, length);
	// printf("median: %d\n", pivot);
	pivot = st_a->start->value;
	// split list (partition)
	i = 0;
	left_part_count = 0;
	node = st_a->start;
	while(i < length)
	{
		if (node->value < pivot)
			pb(st_b, st_a);
		else
		{
			ra(st_a);
			left_part_count++;
		}
		node = st_a->start;
		i++;
	}

	printf("length: %d\n", length);

	//reverse the list back to original position
	if (left_part_count != st_len(st_a))
	{
		i = 0;
		while (i < left_part_count)// optimize the rotation!
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

	printf("asf %d\n", length - left_part_count);
	//first recursion on the smaller half
	quicksort(st_a, st_b, left_part_count);

	// // put on top the right part
	if (length != st_len(st_a))
	{
		i = 0;
		while (i < length)
		{
			ra(st_a);
			i++;
		}
	}
	
	// //recursion for the right part
	quicksort(st_a, st_b, length - left_part_count);

	//rotate list back to original position
	i = 0;
	while (i < length - left_part_count)
	{
		ra(st_a);
		i++;
	}

}

// //  quicksort(int n)
// //     if n == 1 return

// //     int top_half_len = 0


// // 	get the average number(if equal get the max)

// 	// split list
// 	i = 0;
// 	left_part_count = 0;
// 	while(i < n)
// 	{
// 		if (value < pivot)
// 			push_b();
// 		else
// 		{
// 			rotate_a();
// 			left_part_count++;
// 		}
// 		i++;
// 	}


// 	//reverse the list back to original position
// 	///// if left_part_count == current stack a length dont do anything
// 	i = 0;
// 	while (i < left_part_count)
// 	{
// 		reverse_rotate();
// 		i++;
// 	}
	
// 	// push back on top smaller half
// 	while (st_b->start)
// 	{
// 		push_a();
// 	}

// 	//first recursion on the smaller half
// 	quicksort(n - left_part_count);// bottom half name doesnt seem accurate

// 	// put on top the right part
// 	i = 0;
// 	while (i < n - left_part_count)
// 	{
// 		rotate_a();
// 		i++;
// 	}
	
// 	//recursion for the right part
// 	quicksort(n - left_part_count);

// 	//rotate list back to original position
// 	i = 0;
// 	while (i < n - left_part_count)
// 	{
// 		rotate_a();
// 		i++;
// 	}
// }


// // suppose pivot is the median

// /* PARTITION FUNCTION
// 	partitionIndex -> index of partition

// 	p_index -> index of the pivot
// 	i -> count how many number pushed to stack b

// 	compare pivot with first element
// 	while (pivot index > 0)
// 	{
// 		if (pivot < arr[0])
// 			rotate();
// 		else // if less then the pivot push in stack b
// 		{
// 			push_b()
// 			i++;
// 		}
// 		p_index--;
// 	}
// 	// now we have all the elements less than the pivot in stack b
// 	// if we push then back to b we get the stack partitioned
// 	while (i--)
// 		push_a()
	
// 	// Suppose we do not push back the elements to a

// 	now we do the same thing but we keep the lowers numbers and push back to a the 
//  */
