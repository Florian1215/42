#include "libft.h"

int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = ft_wordlen(s, c);
		s += i;
		if (i)
			count++;
	}
	return (count);
}

char	*ft_wordcpy(const char *src, int n)
{
	char	*dest;

	dest = malloc((n + 1) * sizeof(char));
	if (!dest)
		return (0);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char **ft_split(char const *s, char c)
{
	char	**split;
	int		size;
	int		i;
	int		n;

	size = ft_wordcount(s, c);
	split = malloc((size + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		n = ft_wordlen(s, c);
		split[i] = ft_wordcpy(s, n);
		if (!split[i])
            return (0);
		s += n;
	}
	split[size] = 0;
	return (split);
}
