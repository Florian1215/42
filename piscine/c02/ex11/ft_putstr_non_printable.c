/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 10:26:14 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/10 10:16:46 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convhex(unsigned char c)
{
	char	*hextab;

	hextab = "0123456789abcdef";
	ft_putchar(hextab[c / 16]);
	ft_putchar(hextab[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > 126)
		{
			write(1, "\\\\", 1);
			ft_convhex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
