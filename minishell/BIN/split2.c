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
	return (++*i);
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
			len += skip_char(s, &i, s[i]) - 2;
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
		s += i;
		if (i)
			ct++;
	}
	return (ct);
}

static char	*word_cpy(const char *src, int n)
{
	char	*res;

	res = malloc((n + 1) * sizeof(char));
	if (!res)
		return (0);
	res[n] = '\0';
	while (n--)
		res[n] = src[n];
	return (res);
}

void	free_split(char **split, int i)
{
	if (!split)
		return ;
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
}

char	**split2(char const *s, int sep)
{
	char	**split;
	int		ct_word;
	int		i;
	int		n;

	ct_word = ct_words(s, sep);
	split = malloc((ct_word + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	while (++i < ct_word)
	{
		while (*s && *s == sep)
			s++;
		n = len_word(s, sep);
		split[i] = word_cpy(s, n);
		if (!split[i])
			return (free_split(split, --i), NULL);
		s += n;
	}
	return (split[ct_word] = NULL, split);
}

int	main(void)
{
	char	*line = "\"salut yo\"\0";
	int		i;
	char	**res;

	printf("%s len %d\n", line, len_word(line, ' '));
	res = split2(line, ' ');
	i = -1;
	while (res[++i])
		printf("'%s'\n", res[i]);
}
