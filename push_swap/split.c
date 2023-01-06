/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:57:29 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/02 21:40:52 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_len(char const *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	return (len);
}

int	ct_word(char const *s)
{
	int	i;
	int	ct;

	ct = 0;
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		i = word_len(s);
		s += i;
		if (i)
			ct++;
	}
	return (ct);
}

static char	*word_cpy(const char *src, int n)
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

char	**free_split(char **split, int i)
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
	return (0);
}

char	**split_(char const *s)
{
	char	**split;
	int		n_word;
	int		i;
	int		n;

	n_word = ct_word(s);
	split = malloc((n_word + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	while (++i < n_word)
	{
		while (*s && *s == ' ')
			s++;
		n = word_len(s);
		split[i] = word_cpy(s, n);
		if (!split[i])
			return (free_split(split, i - 1));
		s += n;
	}
	return (split[n_word] = NULL, split);
}
