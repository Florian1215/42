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
		else if (env->value > str_len(s))
			env->value -= str_len(s);
		else
			env->value = 0;
		if (env->dot && env->precision > str_len(s))
			env->precision = str_len(s);
	}
//	printf("%d - %d\n", env->precision, env->value);
	if (!*s && env->value)
	{
		if (!env->dot)
			env->value--;
		put_char(env, ' ', TRUE);
	}
	while (*s)
		put_char(env, *s++, TRUE);
}
