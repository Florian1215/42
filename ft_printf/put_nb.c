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

int	is_upper(int c)
{
	return (c > 'A' && c < 'Z');
}

int	to_upper(int c)
{
	return (c + (('A' - 'a') * !is_upper(c)));
}

static int	nb_len(t_llu nb, t_llu len_base)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= len_base;
		len++;
	}
	return (len);
}

void	put_unsigned(t_env *env, t_llu nb, t_bases b, int decrease_value)
{
	static t_base	base[3] = {{"0123456789", 10}, {"0123456789abcdef", 16}, \
							{"0123456789ABCDEF", 16}};

	if (decrease_value)
		env->value -= nb_len(nb, base[b].len);
	if (nb >= base[b].len)
		put_unsigned(env, nb / base[b].len, b, 0);
	put_char(env, base[b].base[nb % base[b].len]);
}

void	put_nbr_base(t_env *env, int n)
{
	unsigned int	nb;

	if (n < 0)
		put_char(env, '-');
	else if (env->space)
		put_char(env, ' ');
	else if (env->plus)
		put_char(env, '+');
	if (n < 0)
		nb = -n;
	else
		nb = n;
	put_unsigned(env, nb, DEC, 1);
}

void	put_hexa(t_env *env, t_llu nb, int upper)
{
	static char	ox[2][3] = {"0x", "0X"};

	env->value -= nb_len(nb, 16);
	if (env->hashtag)
		put_str(env, ox[upper]);
	put_unsigned(env, nb, HEX_L + upper, 0);
}
