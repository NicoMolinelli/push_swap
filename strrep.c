#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

char	*strrep(char* str, char* find, char* rep)
{
	char *p;
	char* join;

	if (!ft_strlen(find))
		return (str);
	join = ft_strdup(str);
	p = ft_strchr(join, *find);
	while (p)
	{
		if (ft_strncmp(p, find, ft_strlen(find)))
		{
			p = ft_strchr(++p, *find);
			continue;
		}
		// part before
		char* sub = ft_substr(join, 0, p - join);
		printf("sub: %s\n", sub);
		// check
		//add replace str
		join = ft_strjoin(sub, rep);
		// part after
		join = ft_strjoin(join, p + ft_strlen(find));

		p = ft_strchr(++p, *find);
		printf("p: %s\n", p);
	}
	return (join);
}

int main()
{
	char s[] = "primapodopo";


	char* str = strrep(s, "po", "pino");

	printf("str: %s\n", str);
	printf("res: primapinodopino\n");

	free(str);
}
