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

static void	set_flags_str(t_env *env, char *s)
{
	int	len_str;

	len_str = str_len(s);
	if (env->values[LENGTH])
	{
		if (env->flags[DOT] && env->values[DOT] < len_str)
			env->values[LENGTH] -= env->values[DOT];
		else if (env->values[LENGTH] > len_str)
			env->values[LENGTH] -= len_str;
		else
			env->values[LENGTH] = 0;
		if (env->flags[DOT] && env->values[DOT] > len_str)
			env->values[DOT] = len_str;
	}
	if (env->flags[ZERO] && env->flags[DOT] && env->values[DOT] < len_str)
		len_str = env->values[DOT];
	if (env->flags[ZERO] && env->values[ZERO] > len_str)
	{
		while (env->values[ZERO]-- - len_str)
			put_char(env, '0', 0);
	}
}

void	put_str(t_env *env, char *s)
{
	if (s == NULL)
		s = "(null)";
	set_flags_str(env, s);
	if (!*s && env->values[LENGTH])
	{
		if (!env->flags[DOT])
			env->values[LENGTH]--;
		put_char(env, ' ', 1);
	}
	while (*s)
		put_char(env, *s++, 1);
}
