#include <sort.h>
#include <libft.h>
#include <actions.h>

// void	sort_4ab(t_stack* a, t_stack* b)
// {
// 	int	min;

// 	min = st_min(a, 4);
// 	smart_to_top(a, min);
// 	push(b, a);
// 	sort_3(a);
// 	push(a, b);
// }

// void	sort_4ba(t_stack* b, t_stack* a)
// {
// 	int	max;

// 	max = st_max(b, 4);
// 	smart_top(b, max);
// 	push(a, b);
// 	sort_3(b);
// 	push(a, b);
// }

void	sort(t_stacks* ss, int length)
{
	// are sorted?
	//maybe lookup table?
	if (length <= 5)
		handSort(ss, length);
	else if (length <= 10)
		select_sort(ss, length);
	// else
	// 	select_sort(ss, length);
	else
		quicksortA(ss, length);
	pattern_check(ss);
}

// rb -> pa -> rrb -> pb
// |
// sb

// rb -> pa -> rrb
// |
// sb -> pa