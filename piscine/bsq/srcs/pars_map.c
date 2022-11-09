/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:09:31 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/23 15:09:32 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_len_col(char *content)
{
	int	len;

	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	return (len);
}

char	**ft_map(char *content, int line, int col)
{
	int		i;
	char	**map;
	int		j;

	map = malloc(sizeof(char *) * line);
	i = 0;
	while (i < line)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * (col + 1));
		while (j < col)
		{
			map[i][j] = *content++;
			j++;
		}
		map[i][j] = '\0';
		content ++;
		i++;
	}
	return (map);
}

t_map	ft_pars_map(char *content)
{
	t_map	m;
	int		i;

	i = 0;
	while (content[i] != '\n')
		i++;
	i --;
	m.fill = content[i--];
	m.obs = content[i--];
	m.empty = content[i];
	m.line = ft_atoi(content, i);
	while (*content != '\n')
		content++;
	content++;
	m.col = ft_len_col(content);
	m.map = ft_map(content, m.line, m.col);
	return (m);
}
