/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nb_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:48:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/05 09:48:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	put_nb_flags_zero_dot(t_env *env, t_llu nb, int unsign, int len_nb)
{
	if (env->flags[ZERO] && env->values[ZERO] > len_nb - unsign && \
		(!env->flags[DOT] || env->values[DOT] < env->values[ZERO]))
	{
		while (env->values[ZERO]-- - len_nb + unsign)
			put_char(env, '0', 0);
	}
	if (env->flags[DOT])
	{
		if (env->values[DOT] < len_nb - (int)unsign && nb)
			env->values[DOT] = len_nb;
		else
			env->values[DOT] += unsign;
		while (env->values[DOT] - len_nb > 0)
			put_char(env, '0', 1);
	}
}

static void	put_nb_flags_one_c(t_env *env, t_llu nb, int unsign, t_bases *b)
{
	if ((env->flags[HASHTAG] || *b == 3) && *b && (nb || *b == 3))
	{
		env->values[LENGTH] -= 2;
		env->values[ZERO] -= 2;
		if (*b == 3)
			*b = 1;
		put_char(env, '0', 0);
		put_char(env, "xX"[--*b], 0);
	}
	else if (unsign || env->flags[PLUS] || (env->flags[SPACE] && \
		(env->values[LENGTH] <= 0 || env->flags[ZERO])))
	{
		if (env->values[LENGTH] && !unsign)
			env->values[LENGTH]--;
		if (unsign)
			put_char(env, '-', 0);
		else if (env->flags[PLUS])
			put_char(env, '+', 0);
		else
			put_char(env, ' ', 0);
		if (env->flags[ZERO])
			env->values[ZERO]--;
	}
}

void	put_nb_flags(t_env *env, t_llu nb, int unsign, t_bases b)
{
	int			len_nb;

	len_nb = nb_len(nb, 10 + (6 * (b > 0))) + (nb == 0) + unsign;
	if (env->values[LENGTH] > 0)
	{
		env->values[LENGTH] -= len_nb - (nb == 0 && !env->values[DOT] \
			&& env->flags[DOT]);
		if (env->flags[DOT] && env->values[DOT] > len_nb - (int)unsign)
			env->values[LENGTH] -= env->values[DOT] - len_nb + unsign;
	}
	put_nb_flags_one_c(env, nb, unsign, &b);
	put_nb_flags_zero_dot(env, nb, unsign, len_nb);
}
