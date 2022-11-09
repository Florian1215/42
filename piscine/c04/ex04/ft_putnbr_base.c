/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:08:25 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/15 19:35:34 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int n, unsigned int b, char *base)
{
	if (n > b - 1)
		ft_putnbr(n / b, b, base);
	ft_putchar(base[n % b]);
}

int	ft_check_base(char *base)
{
	int	b;
	int	i;

	b = 0;
	while (base[b] != '\0')
	{
		if (base[b] == '+' || base[b] == '-')
			return (0);
		if (b != 0)
		{
			i = b;
			while (i != 0)
			{
				i--;
				if (base[b] == base[i])
					return (0);
			}
		}
		b++;
	}
	return (b);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b;

	b = ft_check_base(base);
	if (b > 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		ft_putnbr(nbr, b, base);
	}	
}
