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

static void	ft_putnb(t_time nb)
{
	if (nb >= 10)
		ft_putnb(nb / 10);
	ft_putchar('0' + nb % 10);
}

static void	ft_putstr(char *s)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
		ft_putchar(*s++);
}

static void	ft_format(const char c, va_list	args)
{
	if (c == '%')
		ft_putchar('%');
	else if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		ft_putnb(va_arg(args, t_time));
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
			ft_format(*format++, args);
		}
		else
			ft_putchar(*format++);
	}
	va_end(args);
}
