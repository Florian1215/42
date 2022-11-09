/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:40:14 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 11:57:52 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int size)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * size);
	if (!res)
		return (0);
	i = 0;
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_error(int dict)
{
	if (dict)
		ft_putstr("Dict Error\n");
	else
		ft_putstr("Error\n");
}
