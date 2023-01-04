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

t_bool	is_upper(int c)
{
	return (c > 'A' && c < 'Z');
}

int	to_upper(int c)
{
	return (c + (('A' - 'a') * !is_upper(c)));
}

int	nb_len(t_llu nb, t_llu len_base)
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

void	put_unsigned(t_env *env, t_llu nb, t_bases b)
{
	static t_base	base[3] = {{"0123456789", 10}, {"0123456789abcdef", 16}, \
							{"0123456789ABCDEF", 16}};

	if (nb >= base[b].len)
		put_unsigned(env, nb / base[b].len, b);
	put_char(env, base[b].base[nb % base[b].len], TRUE);
}

static void	put_nb_flags(t_env *env, t_llu nb, t_bool unsign, t_bases b)
{
	int			len_nb;

//	printf("%d - %d\n", env->zero, env->space);
	len_nb = nb_len(nb, 10 + (6 * (b > 0))) + (nb == 0) + unsign;
	if (env->value)
	{
		env->value -= len_nb - (nb == 0 && !env->precision && env->dot);
		if (env->dot && env->precision > len_nb - (int)unsign)
			env->value -= env->precision - len_nb + unsign;
	}
//	printf("\n%d - %d\n", len_nb, env->value);
	if ((env->hashtag || b == 3) && b && (nb || b == 3))
	{
		env->value -= 2;
		env->nb_zero -= 2;
		if (b == 3)
			b = 1;
		put_char(env, '0', FALSE);
		put_char(env, "xX"[--b], FALSE);
	}
	else if (unsign || env->plus || (env->space && (env->value <= 0 || env->zero)))
	{
		if (env->value && !unsign)
			env->value--;
		if (unsign)
			put_char(env, '-', FALSE);
		else if (env->plus)
			put_char(env, '+', FALSE);
		else
			put_char(env, ' ', FALSE);
		if (env->zero)
			env->nb_zero--;
	}
//	printf("\n%d - %d\n", env->value, env->precision);
//	printf("\n%d - %d\n", env->value, env->precision);
	if (env->zero && env->nb_zero > len_nb - (int)unsign && env->precision < env->nb_zero)
	{
//		printf("\nnb zero %d - presi %d - len_nb %d\n", env->nb_zero, env->precision, len_nb);
		while (env->nb_zero-- - len_nb + unsign)
			put_char(env, '0', FALSE);
	}
	if (env->dot)
	{
//		printf("\nval %d - presi %d - len_nb %d\n", env->value, env->precision, len_nb);
		if (env->precision < len_nb - (int)unsign && nb)
			env->precision = len_nb;
		else
			env->precision += unsign;
		while (env->precision - len_nb > 0)
			put_char(env, '0', TRUE);
	}
}

void	put_u(t_env *env, t_llu nb)
{
	put_nb_flags(env, nb, FALSE, DEC);
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

void	put_hexa(t_env *env, t_llu nb, t_bool upper)
{
	put_nb_flags(env, nb, FALSE, HEX + upper);
	if (upper == 2)
		upper = 0;
	put_unsigned(env, nb, HEX + upper);
}
