#include <sort.h>
#include <actions.h>

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

void	sort(t_stack* sta, t_stack* stb, int length)
{
	if (length == 1)
		return ;
	if (length == 2)
		sort_2(sta);
	else if (length == 3)
		sort_3(sta);
	else
		select_sort(sta, stb);
}
