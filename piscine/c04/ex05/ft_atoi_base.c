/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:08:58 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/13 09:08:27 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	return (b);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;
	int	b;

	sign = 1;
	res = 0;
	i = 0;
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
