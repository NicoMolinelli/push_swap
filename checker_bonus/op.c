#include <checker.h>

void	set_items(t_item items[10])
{
	items[0].key = "sa";
	items[0].op = swapA;
	items[1].key = "sb";
	items[1].op = swapB;
	// items[2] = swapS;
	items[3].key = "pa";
	items[3].op = pushA;
	items[4].key = "pb";
	items[4].op = pushB;
	items[5].key = "ra";
	items[5].op = rotateA;
	items[6].key = "rb";
	items[6].op = rotateB;
	// items[7] = rotateR;
	items[8].key = "rra";
	items[8].op = reverseA;
	items[9].key = "rrb";
	items[9].op = reverseB;
	// items[9] = reverseR;
}
