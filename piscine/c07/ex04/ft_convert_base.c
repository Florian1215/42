/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:38:44 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/17 15:22:06 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_lennbr(unsigned int nb, unsigned int b)
{
	int	len;

	len = 0;
	while (nb >= b)
	{
		nb /= b;
		len++;
	}
	return (++len);
}

int	ft_isbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_checkbase(char *base)
{
	int	b;
	int	i;

	b = 0;
	while (base[b] != '\0')
	{
		if (base[b] == '+' || base[b] == '-' || base[b] <= ' ' \
				|| base[b] == 127)
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
	if (b < 2)
		return (0);
	return (b);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	b;

	sign = 1;
	res = 0;
	b = ft_checkbase(base);
	if (b < 2)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -sign;
	}
	while (ft_isbase(*str, base) >= 0)
	{
		res = res * b + ft_isbase(*str, base);
		str++;
	}
	return (res * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	nb;
	int				nb_b10;
	char			*res;
	int				i;

	if (!ft_checkbase(base_from) || !ft_checkbase(base_to))
		return (0);
	nb_b10 = ft_atoi_base(nbr, base_from);
	if (nb_b10 < 0)
		nb = -nb_b10;
	else
		nb = nb_b10;
	i = ft_lennbr(nb, ft_checkbase(base_to)) + ((nb_b10 < 0));
	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	while (i--)
	{
		res[i] = base_to[nb % ft_checkbase(base_to)];
		nb /= ft_checkbase(base_to);
	}
	if (nb_b10 < 0)
		res[0] = '-';
	return (res);
}
