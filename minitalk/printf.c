/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:11:12 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 16:56:17 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

static void	format(const char c, va_list	args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 'd')
		ft_putnbr(va_arg(args, int));
}

void	ft_printf(const char *format, ...)
{
	va_list	valist;

	va_start(valist, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!*++format)
				break ;
			format(*format++, valist);
		}
		else
			ft_putchar(*format++);
	}
	va_end(valist);
}
