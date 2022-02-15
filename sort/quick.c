void	quicksort(t_stack* st, t_node* start, t_node* end)
{
	// choose a pivot
	// partitioning -> all value < pivot to left and the > on the right
	// first recursion(stack, start, pivot index -1)

}

// suppose pivot is the last element

/* PARTITION FUNCTION
	partitionIndex -> index of partition

	p_index -> index of the pivot
	i -> count how many number pushed to stack b

	compare pivot with first element
	while (pivot index > 0)
	{
		if (pivot < arr[0])
			rotate();
		else // if less then the pivot push in stack b
		{
			push_b()
			i++;
		}
		p_index--;
	}
	// now we have all the elements less than the pivot in stack b
	// if we push then back to b we get the stack partitioned
	while (i--)
		push_a()
	
	// Suppose we do not push back the elements to a

	now we do the same thing but we keep the lowers numbers and push back to a the 
 */