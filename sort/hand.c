#include <sort.h>
#include <actions.h>

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

void	handSort(t_stacks* ss, int length)
{
	int	min;
	int	i;
	// prendi i due piu piccoli
	// li sposti in b
	// sorti a con 3
	// sposti i piu piccoli in a
	// swappi
	if (length == 1)
		return ;
	if (length == 2)
		return (sort_2(ss));
	else if (length == 3)
		return (sort_3(ss));
	else if (is_sorted(ss->a, length))
		return ;
	i = 0;
	while (length > 3)
	{
		min = st_min(ss->a, length);
		smart_top(ss, min);
		pushB(ss);
		length--;
		i++;
	}
	sort_3(ss);
	while(i--)
		pushA(ss);
	sort_2(ss);
}
