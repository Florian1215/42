/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:30:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/11 14:30:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

t_bool	split_once(char *str, char **s1, char **s2, int sep)
{
	int	idx_split;
	int	i;
	int	j;

	idx_split = find_char(str, sep);
	if (idx_split == -1)
		return (ERROR);
	*s1 = malloc(sizeof(char) * (idx_split + 1));
	if (!*s1)
		return (ERROR);
	i = -1;
	while (++i < idx_split)
		(*s1)[i] = str[i];
	(*s1)[i++] = '\0';
	*s2 = malloc(sizeof(char) * (str_len(str) - idx_split + 1));
	if (!*s2)
		return (free(*s1), ERROR);
	j = 0;
	while (str[i])
		(*s2)[j++] = str[i++];
	return ((*s2)[j] = '\0', SUCCESS);
}
