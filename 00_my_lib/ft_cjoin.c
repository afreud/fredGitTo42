
char	*ft_cjoin(char const *s1, char const *s2, char c)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);
	while (*s1)
		dest[i++] = *s1++;
	dest[i++] = c;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
