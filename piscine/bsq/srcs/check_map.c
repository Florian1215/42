/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:08:53 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/23 15:09:14 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_line2(char *str, int i, int line)
{
	int	check;

	check = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			if (line == check)
				check = 0;
			else
				return (0);
		}
		else
			check++;
	}
	return ((str[i - 1] == '\n'));
}

int	ft_check_line(char *str)
{
	int	line;
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i] || !str[++i])
		return (0);
	line = 0;
	while (str[i] != '\n' && str[i++])
		line++;
	if (!str[i])
		return (0);
	return (ft_check_line2(str, i, line));
}

int	ft_check_data(char *content)
{
	int		i;
	char	f;
	char	o;

	i = 0;
	while (content[i] != '\n' && content[i])
		i++;
	if (content[i] != '\n')
		return (0);
	i--;
	if (!ft_isprintable(content[i]) || i < 1)
		return (0);
	f = content[i--];
	if (i == 0 || !ft_isprintable(content[i]) || content[i] == f)
		return (0);
	o = content[i--];
	if (i == 0 || !ft_isprintable(content[i]) || \
			content[i] == o || content[i] == f)
		return (0);
	return (ft_atoi(content, i));
}

int	ft_check_only_char(char *content)
{
	int		i;
	char	o;
	char	e;

	i = 0;
	while (content[i] != '\n' && content[i])
		i++;
	if (content[i] != '\n')
		return (0);
	i -= 2;
	o = content[i--];
	e = content[i];
	while (content[i] != '\n' && content[i])
		i++;
	i++;
	while (content[i])
	{
		if (content[i] != o && content[i] != e && content[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
