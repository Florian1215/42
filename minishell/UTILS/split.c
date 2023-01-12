/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:57:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/08 10:57:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_char(char const *s, int *i, int c)
{
	++*i;
	while (s[*i] && (s[*i] != c))
		++*i;
	return (*i);
}

static int	len_word(char const *s, int sep)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (s[++i] && s[i] != sep)
	{
		if (s[i] == '"' || s[i] == '\'')
			len += skip_char(s, &i, s[i]) - 1;
		else
			len++;
	}
	return (len);
}

static int	ct_words(char const *s, int sep)
{
	int	i;
	int	ct;

	ct = 0;
	while (*s)
	{
		while (*s && *s == sep)
			s++;
		i = len_word(s, sep);
		if (s[0] == '"' || s[0] == '\'')
			i += 2;
		s += i;
		if (i)
			ct++;
	}
	return (ct);
}

static char	*word_cpy(const char *s, int *len)
{
	char	*res;
	int		skip_char;
	int		i;

	res = malloc((*len + 1) * sizeof(char));
	if (!res)
		return (0);
	skip_char = 0;
	if (s[0] == '"' || s[0] == '\'')
		skip_char++;
	i = -1;
	while (++i < *len)
		res[i] = s[i + skip_char];
	if (s[i + skip_char] == '"' || s[i + skip_char] == '\'')
		skip_char++;
	*len += skip_char;
	return (res[i] = '\0', res);
}

char	**split(char const *s, int sep)
{
	char	**split;
	int		ct_word;
	int		k;
	int		word_len;

	if (!s)
		return (NULL);
	ct_word = ct_words(s, sep);
	split = malloc(sizeof(char *) * (ct_word + 1));
	if (!split)
		return (0);
	k = -1;
	while (++k < ct_word)
	{
		while (*s && *s == sep)
			s++;
		word_len = len_word(s, sep);
		split[k] = word_cpy(s, &word_len);
		if (!split[k])
			return (free_split(split, --k), NULL);
		s += word_len;
	}
	return (split[ct_word] = NULL, split);
}
