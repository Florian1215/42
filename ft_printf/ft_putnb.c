/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:08:56 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/10 09:08:56 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_nblen(unsigned int nb, int n_base)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= n_base;
		len++;
	}
	return (len);
}

void	ft_putunsigned_long(unsigned long int nb,
			char *base, int n_base, int *len)
{
	if (nb >= (unsigned long)n_base)
	{
		ft_putunsigned_long(nb / n_base, base, n_base, len);
		nb %= n_base;
	}
	ft_putchar(base[nb], len);
}

void	ft_putunsigned(unsigned int nb,
			char *base, int n_base, int *len)
{
	if (nb >= (unsigned)n_base)
	{
		ft_putunsigned(nb / n_base, base, n_base, len);
		nb %= n_base;
	}
	ft_putchar(base[nb], len);
}

void	ft_putnbr_base(int n, char *base, int *len)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-', len);
		nb = -n;
	}
	else
		nb = n;
	ft_putunsigned(nb, base, ft_strlen(base), len);
}
