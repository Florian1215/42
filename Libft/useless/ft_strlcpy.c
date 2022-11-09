unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	int				len_src;
	unsigned int	i;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	i = 0;
	if (n > 0)
	{
		while (src[i] != '\0' && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len_src);
}