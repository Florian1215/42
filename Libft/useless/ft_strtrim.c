#include "libft.h"

int	ft_strin(char c, char const *str)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	to;
	size_t	i;
	char *res;
	
	
	st = 0;
	while (s1[st] && ft_strin(s1[st], set))
		st++;
	to = ft_strlen((char *)s1) - 1;
	while (to > st && ft_strin(s1[to], set))
		to--;
	res = malloc(sizeof(char) * (to - st + 1));
	if (!res)
		return (0);
	i = 0;
	while (st <= to)
		res[i++] = s1[st++];
	res[i] = '\0';
	return (res);
}
