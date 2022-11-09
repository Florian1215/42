/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:14:51 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/16 17:16:29 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char *str, char *charset)
{
	while (*charset)
		if (*str == *charset++)
			return (1);
	return (0);
}

int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_sep(str + i, charset))
		i++;
	return (i);
}

int	ft_wordcount(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_sep(str, charset))
			str++;
		i = ft_wordlen(str, charset);
		str += i;
		if (i)
			count++;
	}
	return (count);
}

char	*ft_wordcpy(char *src, int n)
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

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		size;
	int		i;
	int		n;

	size = ft_wordcount(str, charset);
	split = malloc((size + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	while (++i < size)
	{
		while (*str && ft_is_sep(str, charset))
			str++;
		n = ft_wordlen(str, charset);
		split[i] = ft_wordcpy(str, n);
		if (!split[i])
			return (0);
		str += n;
	}
	split[size] = 0;
	return (split);
}
