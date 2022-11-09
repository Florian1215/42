/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:48:35 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 22:08:52 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned long long int	ft_atoi(char *str)
{
	unsigned long long int	res;

	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	return (res);
}

int	ft_lennb(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned long long int nb)
{
	char	*res;
	int		len;

	len = ft_lennb(nb) + (nb == 0);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
