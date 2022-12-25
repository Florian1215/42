/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:00:14 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/25 12:00:16 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_unsigned(t_llu nb, t_bases b, int *len)
{
	static t_base	base[3] = {{"0123456789", 10}, {"0123456789abcdef", 16}, \
							{"0123456789ABCDEF", 16}};

	if (nb >= base[b].len)
		put_unsigned(nb / base[b].len, b, len);
	put_char(base[b].base[nb % base[b].len], len);
}

void	put_nbr_base(int n, int *len)
{
	unsigned int	nb;

	if (n < 0)
	{
		put_char('-', len);
		nb = -n;
	}
	else
		nb = n;
	put_unsigned(nb, DEC, len);
}
