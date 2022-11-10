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

#include "libft.h"

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

void	ft_putunsigned_nb(unsigned long int nb, char *base, int n_base)
{
	if (nb >= (unsigned long)n_base)
	{
		ft_putunsigned_nb(nb / n_base, base, n_base);
		nb %= n_base;
	}
	ft_putchar(base[nb]);
}

void	ft_putnbr_base(int n, char *base)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	ft_putunsigned_nb(nb, base, ft_strlen(base));
}

void	ft_putnbr_dec(float n)
{
	ft_putnbr_base(n, ft_dec());
}
