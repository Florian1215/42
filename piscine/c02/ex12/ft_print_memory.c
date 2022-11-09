/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 10:26:55 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/09 21:26:28 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthexa(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_printvalue(char *s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (s[i] < 32 || s[i] == 127)
			write(1, ".", 1);
		else
			write(1, &s[i], 1);
		i++;
	}
}

void	ft_printvalue_hex(char *s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!(i % 2))
			write(1, " ", 1);
		ft_puthexa(s[i]);
		i++;
	}
	while (i < 16)
	{
		if (i++ % 2)
			write(1, "   ", 3);
		else
			write(1, "  ", 2);
	}
	write(1, " ", 1);
	ft_printvalue(s, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < size)
	{
		write(1, "0", 1);
		j = 48;
		while (j >= 0)
		{
			ft_puthexa((unsigned long int)(addr + i) >> j & 0xff);
			j -= 8;
		}
		write(1, ":", 1);
		if (size - i < 16)
			ft_printvalue_hex(addr + i, size - i);
		else
			ft_printvalue_hex(addr + i, 16);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
