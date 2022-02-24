#include <sort.h>
#include <actions.h>


// fast way to put the node with value n as first element in stack st
static void	smart_to_top(t_stack* st, int n)
{
	int	len;
	int	index;

	len = st_len(st);
	index = st_index(n, st);
	// normal rotate
	if (index <= len / 2)
	{
		while (index)
		{
			index--;
			ra(st);//TODO handle name
		}
	}
	else//reverse rotate
	{
		while (index < len)
		{
			rra(st);//TODO handle name
			index++;
		}
	}
}

// Sort for only two numbers
void	sort_2(t_stack* st)
{
	if (st->start->value > st->start->next->value)
		sa(st);
}
// sort 3 numbers
void	sort_3(t_stack* st)
{
	int	start;
	int	middle;
	int	end;

	start = st->start->value;
	middle = st->start->next->value;
	end = st->end->value;
	if (middle < start && start < end)
		sa(st);
	else if (end < middle && middle < start)
	{
		sa(st);
		rra(st);
	}
	else if (start > end && end > middle)
		ra(st);
	else if (start < end && end < middle)
	{
		sa(st);
		ra(st);
	}
	else if (middle > start && start > end)
		rra(st);
}

void	sort_4ab(t_stack* a, t_stack* b)
{
	int	min;

	min = st_min(a, 4);
	smart_to_top(a, min);
	pb(b, a);
	sort_3(a);
	pa(a, b);
}

// void	sort_4ba(t_stack* b, t_stack* a)
// {
// 	int	max;

// 	max = st_max(b, 4);
// 	smart_top(b, max);
// 	pa(a, b);
// 	sort_3(b);
// 	pb(a, b);
// }

void	sort(t_stack* sta, t_stack* stb, int length)
{
	//maybe lookup table?
	if (length == 1)
		return ;
	if (length == 2)
		sort_2(sta);
	else if (length == 3)
		sort_3(sta);
	// else if (length == 4)
	// 	sort_4ab(sta, stb);
	else
		quicksort(sta, stb, length);
}
