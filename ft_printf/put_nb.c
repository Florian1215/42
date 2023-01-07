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

#include "ft_printf.h"

void	put_unsigned(t_env *env, t_llu nb, t_bases b)
{
	static t_base	base[3] = {{"0123456789", 10}, {"0123456789abcdef", 16}, \
							{"0123456789ABCDEF", 16}};

	if (nb >= base[b].len)
		put_unsigned(env, nb / base[b].len, b);
	put_char(env, base[b].base[nb % base[b].len], 1);
}

void	put_u(t_env *env, t_llu nb)
{
	put_nb_flags(env, nb, 0, DEC);
	put_unsigned(env, nb, DEC);
}

void	put_nbr_base(t_env *env, int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	put_nb_flags(env, nb, n < 0, DEC);
	put_unsigned(env, nb, DEC);
}

void	put_hexa(t_env *env, t_llu nb, int upper)
{
	put_nb_flags(env, nb, 0, HEX + upper);
	if (upper == 2)
		upper = 0;
	put_unsigned(env, nb, HEX + upper);
}
