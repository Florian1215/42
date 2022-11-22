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

void	ft_putunsigned(unsigned long long int nb,
			char *base, int n_base, int *len)
{
	if (nb >= (unsigned long long)n_base)
	{
		ft_putunsigned(nb / n_base, base, n_base, len);
		nb %= n_base;
	}
	ft_putchar(base[nb], len);
}

void	ft_putnbr_base(int n, int *len)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-', len);
		nb = -n;
	}
	else
		nb = n;
	ft_putunsigned(nb, "0123456789", 10, len);
}
