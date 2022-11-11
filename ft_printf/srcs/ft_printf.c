/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:11:12 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/11 10:39:49 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format(const char c, va_list	args, int *len)
{
	if (c == '%')
		ft_putchar('%', len);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_putunsigned_nb(va_arg(args, unsigned long int), ft_hex(), 16, len);
	}
	else if (c == 'u')
		ft_putunsigned_nb(va_arg(args, unsigned int), ft_dec(), 10, len);
	else if (c == 'i' || c == 'd')
		ft_putnbr_base(va_arg(args, int), ft_dec(), len);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, int), ft_hex(), len);
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, int), ft_hex_u(), len);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	int		len;

	va_start(valist, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_format(*++format, valist, &len);
			format++;
		}
		else
			ft_putchar(*format++, &len);
	}
	va_end(valist);
	return (len);
}
