/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:10:04 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 11:06:27 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putvalue(t_dict *d, unsigned long long int n, int space)
{
	if (space)
		ft_putchar(' ');
	ft_putstr(ft_in_dict(d, ft_itoa(n))->value);
}

int	ft_end_number(t_dict *d, unsigned long long int n, int space)
{
	unsigned long long int	i;

	i = 1000000000;
	while (i >= 1000)
	{
		if (i == n)
			return (0);
		i /= 1000;
	}
	if (n == 100 || !ft_in_dict(d, ft_itoa(n)))
		return (0);
	ft_putvalue(d, n, space);
	return (1);
}

int	ft_print_digits(t_dict *d, unsigned long long int n, int space)
{
	n %= 1000;
	if (n >= 100)
	{
		ft_putvalue(d, n / 100, space++);
		ft_putvalue(d, 100, space);
		if (n == 100)
			return (space);
	}
	n %= 100;
	if (ft_in_dict(d, ft_itoa(n)))
		ft_putvalue(d, n, space++);
	else
	{
		if (n >= 10)
			ft_putvalue(d, (n / 10) * 10, space++);
		if (n % 10)
			ft_putvalue(d, n % 10, space++);
	}
	return (space);
}

void	ft_print(t_dict *d, char *nb)
{
	unsigned long long int	split;
	int						space;

	while (*nb == '0' && *(nb + 1))
		nb++;
	split = 1000000000;
	space = 0;
	while (*nb)
	{
		if (ft_end_number(d, ft_atoi(nb), space))
			break ;
		while (split > ft_atoi(nb))
			split /= 1000;
		space = ft_print_digits(d, ft_atoi(nb) / split, space);
		if (split > 1)
			ft_putvalue(d, split, space++);
		nb++;
		while (ft_strlen(nb) % 3)
			nb++;
		while (*nb == '0')
			nb++;
	}
	ft_putchar('\n');
}
