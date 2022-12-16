/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:42:02 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/16 11:42:04 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static void	ft_putnb(unsigned int nb, int *len)
{
	if (nb >= 10)
		ft_putnb(nb / n_base, len);
	ft_putchar('0' + nb % 10, len);
}

void	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!*++format)
				break ;
			if (*format == 'd')
				ft_putnb(va_arg(args, unsigned int));
		}
		else
			ft_putchar(*format++);
	}
	va_end(args);
}
