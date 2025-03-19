
char	**ft_clean2(char **t)
{
	int	i;

	i = 0;
	if (t)
	{
		while (t && t[i])
		{
			free(t[i]);
			t[i++] = NULL;
		}
		free(t);
	}
	return (NULL);
}
