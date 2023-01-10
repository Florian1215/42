/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:00:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/08 11:00:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_char(char c, int fd)
{
	write(fd, &c, 1);
}

static int	str_len(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*join_path(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc((str_len(s1) + str_len(s2) + 2) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	res[i++] = '/';
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	return (res[i] = '\0', res);
}

int	str_cmp(char *s1, char *s2)
{
	while (*s1 && *s1++ == *s2++)
		;
	return (*s1 - *s2);
}

int	str_n_cmp(const char *s1, const char *s2, int n)
{
	while (n-- > 1 && *s1 && *s1++ == *s2++)
		;
	return (*s1 - *s2);
}
