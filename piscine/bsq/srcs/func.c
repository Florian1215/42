/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:18:42 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/23 18:18:45 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	ft_strlen(char *str, char end)
{
	int	len;

	len = 0;
	while (str[len] != end && str[len])
		len++;
	return (len);
}

void	ft_error(void)
{
	ft_putstr("map error\n");
}

int	ft_atoi(char *str, int size)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (ft_isdigit(str[i]) && i < size)
		res = res * 10 + str[i++] - '0';
	return (res);
}
