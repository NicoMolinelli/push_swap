void	swap_a(int* stack_a)
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
}

void	swap_b(int* stack_b)
{
	int	temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
}

void	swap_s(int* stack_a, int* stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
