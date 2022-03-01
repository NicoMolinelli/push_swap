#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

#define p1 "ra\npb\nrra\npa\n"
#define p2 "rra\nra\n"
#define p4 "ra\nrra\n"
#define p3 "rrb\nrb\n"

char	*strrep(char* str, char* find, char* rep)
{
	int		i;
	int		find_len;
	char *cp;
	char* join;

	find_len = ft_strlen(find);
	if (!str || !find_len)
		return (str);
	join = str;
	i = 0;
	while (join[i])
	{
		if (!ft_strncmp(&join[i], find, find_len))
		{
			// take the first part
			cp = ft_substr(join, 0, i);
			//add replace str
			cp = ft_strjoin(cp, rep);// leaks
			// part after
			join = ft_strjoin(cp, &join[i + find_len]);// libera il leak
			// free(cp);
			i += find_len;
		}
		else
			i++;
	}
	if (str != join)
		free(str);
	return (join);
}

// int main()
// {
// 	char s[] = "pb\nra\nra\nrra\npb\n";

// 	char *mal = malloc(sizeof(char) * (ft_strlen(s) + 1));
	
// 	ft_strlcpy(mal, s, (ft_strlen(s) + 1));

// 	// ss->str = strrep(ss->str, p1, "sa\n");
// 	mal = strrep(mal, p4, "");
// 	// ss->str = strrep(ss->str, p3, "");

// 	printf("mal: %s\n", mal);
// 	// printf("str: %s\n", str);
// 	// printf("res: primapinodopino\n");

// 	// free(str);
// 	free(mal);
// 	system("leaks a.out");
// }
