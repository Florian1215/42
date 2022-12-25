/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:11:12 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/01 11:55:39 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_char(int c, int *len)
{
	if (*len != -1)
	{
		if (write(1, &c, 1) == -1)
			*len = -1;
		else
			*len += 1;
	}
}

static void	put_str(char *s, int *len)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
		put_char(*s++, len);
}

void	ft_format(const char c, va_list	args, int *len)
{
	if (c == '%')
		put_char('%', len);
	else if (c == 'c')
		put_char(va_arg(args, int), len);
	else if (c == 's')
		put_str(va_arg(args, char *), len);
	else if (c == 'p')
	{
		put_str("0x", len);
		put_unsigned(va_arg(args, t_llu), HEX_L, len);
	}
	else if (c == 'u')
		put_unsigned(va_arg(args, unsigned int), DEC, len);
	else if (c == 'i' || c == 'd')
		put_nbr_base(va_arg(args, int), len);
	else if (c == 'x')
		put_unsigned(va_arg(args, unsigned int), HEX_L, len);
	else if (c == 'X')
		put_unsigned(va_arg(args, unsigned int), HEX_U, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	int		len;

	va_start(valist, format);
	len = 0;
	while (*format && len != -1)
	{
		if (*format == '%')
		{
			if (!*++format)
				break ;
			ft_format(*format++, valist, &len);
		}
		else
			put_char(*format++, &len);
	}
	va_end(valist);
	return (len);
}
