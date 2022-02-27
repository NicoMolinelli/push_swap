#include <sort.h>
#include <libft.h>
#include <actions.h>

int	is_sorted(t_stack* st, int length)
{
	t_node* node;
	t_node* next;
	int		i;

	if (length <= 1)
		return (1);
	node = st->head;
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

// fast way to put the node with value n as first element in stack st
// static void	smart_to_top(t_stack* st, int n)
// {
// 	int	len;
// 	int	index;

// 	len = st_len(st);
// 	index = st_index(n, st);
// 	// normal rotate
// 	if (index <= len / 2)
// 	{
// 		while (index)
// 		{
// 			index--;
// 			rotateA(st);
// 		}
// 	}
// 	else//reverse rotate
// 	{
// 		while (index < len)
// 		{
// 			rev_rotate(st);
// 			index++;
// 		}
// 	}
// }

// Sort for only two numbers
void	sort_2(t_stacks* ss)
{
	if (ss->a->head->value > ss->a->head->next->value)
		swapA(ss);
}

// sort 3 numbers
void	sort_3(t_stacks* ss)
{
	int	head;
	int	middle;
	int	tail;

	head = ss->a->head->value;
	middle = ss->a->head->next->value;
	tail = ss->a->tail->value;
	if (middle < head && head < tail)
		swapA(ss);
	else if (tail < middle && middle < head)
	{
		swapA(ss);
		reverseA(ss);
	}
	else if (head > tail && tail > middle)
		rotateA(ss);
	else if (head < tail && tail < middle)
	{
		swapA(ss);
		rotateA(ss);
	}
	else if (middle > head && head > tail)
		reverseA(ss);
}

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
	//maybe lookup table?
	if (length == 1)
		return ;
	if (length == 2)
		sort_2(ss);
	else if (length == 3)
		sort_3(ss);
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