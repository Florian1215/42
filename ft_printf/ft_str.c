/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:09:48 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/10 09:09:48 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(int c, int *len)
{
	if (*len != -1)
	{
		if (write(1, &c, 1) == -1)
			*len = -1;
		else
			*len += 1;
	}
}

void	ft_putstr(char *s, int *len)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
		ft_putchar(*s++, len);
}
