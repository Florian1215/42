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
	if (env->values[LENGTH])
	{
		if (env->flags[DOT] && env->values[DOT] < str_len(s))
			env->values[LENGTH] -= env->values[DOT];
		else if (env->values[LENGTH] > str_len(s))
			env->values[LENGTH] -= str_len(s);
		else
			env->values[LENGTH] = 0;
		if (env->flags[DOT] && env->values[DOT] > str_len(s))
			env->values[DOT] = str_len(s);
	}
	if (!*s && env->values[LENGTH])
	{
		if (!env->flags[DOT])
			env->values[LENGTH]--;
		put_char(env, ' ', TRUE);
	}
	while (*s)
		put_char(env, *s++, TRUE);
}
