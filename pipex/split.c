/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:02 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/01 11:35:15 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_wordlen(char const *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	return (len);
}

int	ft_countword(char const *s)
{
	int	i;
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		i = ft_wordlen(s);
		s += i;
		if (i)
			count++;
	}
	return (count);
}

static char	*ft_wordcpy(const char *src, int n)
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

char	**ft_free_split(char **split, int i)
{
	if (i == -1)
	{
		i = 0;
		while (split[i])
			i++;
		i--;
	}
	while (i >= 0)
		free(split[i--]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s)
{
	char	**split;
	int		size;
	int		i;
	int		n;

	size = ft_countword(s);
	split = malloc((size + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == ' ')
			s++;
		n = ft_wordlen(s);
		split[i] = ft_wordcpy(s, n);
		if (!split[i])
			return (ft_free_split(split, i - 1));
		s += n;
	}
	split[size] = 0;
	return (split);
}
