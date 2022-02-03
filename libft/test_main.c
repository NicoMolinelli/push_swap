#include <stdio.h>

static int	count_del(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			count++;
		s++;
	}
	return (count);
}

int	main()
{
	// char a[] = "  a    adasdas    34";
	// char del = ' ';
	// printf("%d\n", count_del(a, del));
	printf("%d\n", -57 % 10);
}
