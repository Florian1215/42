/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:09:48 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/23 15:10:21 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_map(t_map m, int size, int line, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.line)
	{
		j = 0;
		while (j < m.col)
		{
			if (i >= line && i < line + size && j >= col && j < col + size)
				ft_putchar(m.fill);
			else if (m.map[i][j] == m.obs)
				ft_putchar(m.obs);
			else
				ft_putchar(m.empty);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_check_obs(t_map m, int size, int line, int col)
{
	int	i;
	int	j;

	if (col == m.col - size + 1)
	{
		col = 0;
		line++;
	}
	if (line == m.line - size + 1)
		return (0);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (m.map[i + line][j + col] == m.obs)
				return (ft_check_obs(m, size, line, col + 1));
			j++;
		}
		i++;
	}
	ft_print_map(m, size, line, col);
	return (1);
}

void	ft_clear_map(t_map m)
{
	int	i;

	i = 0;
	while (i < m.line)
	{
		free(m.map[i]);
		i++;
	}
	free(m.map);
}

void	ft_solve_map(char *content)
{
	int		size;
	t_map	m;

	if (!content || !ft_check_data(content) || !ft_check_line(content) || \
			!ft_check_only_char(content))
		return (ft_error());
	m = ft_pars_map(content);
	if (m.col > m.line)
		size = m.line;
	else
		size = m.col;
	while (size)
	{
		if (ft_check_obs(m, size, 0, 0))
			return (ft_clear_map(m));
		size--;
	}
	ft_clear_map(m);
}
