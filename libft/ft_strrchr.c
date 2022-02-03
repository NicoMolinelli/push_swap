char	*ft_strrchr(const char *s, int c)
{
	char	to_find;
	char	*str;
	char	*last_chr;

	to_find = (char) c;
	str = (char *) s;
	last_chr = 0;
	while (*str)
	{
		if (*str == to_find)
			last_chr = str;
		str++;
	}
	if (*str == to_find)
		return (str);
	return (last_chr);
}
