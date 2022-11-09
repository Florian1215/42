/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:52:54 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/18 13:06:29 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_calculate(int a, char op, int b)
{
	if (op == '+')
		ft_putnbr(a + b);
	else if (op == '-')
		ft_putnbr(a - b);
	else if (op == '*')
		ft_putnbr(a * b);
	else if (op == '/')
	{
		if (b == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr(a / b);
	}
	else if (op == '%')
	{
		if (b == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(a % b);
	}
	else
		ft_putchar('0');
	ft_putchar('\n');
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -sign;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		ft_calculate(ft_atoi(av[1]), av[2][0], ft_atoi(av[3]));
	return (0);
}
