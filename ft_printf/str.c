/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:36:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/03 17:36:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	put_str(t_env *env, char *s)
{
	if (s == NULL)
		s = "(null)";
	if (env->value)
	{
		if (env->dot && env->precision < str_len(s))
			env->value -= env->precision;
		else
			env->value -= str_len(s);
		if (env->dot)
			env->precision += env->value;
	}
	while (*s)
		put_char(env, *s++);
}

void	left_jutify(t_env *env)
{
	int	n;

	if (!env->minus || env->len == -1)
		return ;
	n = env->len - env->start_len;
	env->dot = 0;
	while (env->left_justify-- > n)
		put_char(env, ' ');
}
