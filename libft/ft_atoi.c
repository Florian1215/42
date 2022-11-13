/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:46:25 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/08 08:47:22 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long int	res;
	int				sign;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -sign;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return ((int)res * sign);
}
