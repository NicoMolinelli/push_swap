char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (s[i] && s[i] != chr)
		i++;
	if (s[i] != chr)
		return (0);
	return ((char *)(s + i));
}
