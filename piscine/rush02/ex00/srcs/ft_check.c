/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:45:57 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 11:54:32 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_args(int ac, char **av, char **path, char **nb)
{
	if (ac == 2)
	{
		*path = "numbers.dict";
		*nb = av[1];
	}
	else if (ac == 3)
	{
		*path = av[1];
		*nb = av[2];
	}
	else
		return (0);
	return (1);
}

int	ft_check_nb(char *nb)
{
	int	n;
	int	i;

	if (!*nb)
		return (0);
	n = 0;
	i = 0;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		if (n || nb[i] != '0')
			n++;
		i++;
	}
	return (n <= 12);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isprint(char c)
{
	return (c >= ' ' && c <= '~');
}

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}
