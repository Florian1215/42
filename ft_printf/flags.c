/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:24:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/04 16:40:35 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	atoi_(t_env *env, const char *s, t_flags flag)
{
	unsigned long int	res;

	res = 0;
	while (s[env->i] && is_digit(s[env->i]))
	{
		res = res * 10 + s[env->i++] - '0';
		if (res > INT_MAX)
			env->len = -1;
	}
	if (flag != LENGTH)
		env->flags[flag] = 1;
	if (flag != LENGTH && env->last_flag != flag)
		env->last_flag = flag;
	return ((int)res);
}

static void	set_all_flags(t_env *env, t_flags flag, const char *s)
{
	env->i++;
	if (flag > DOT)
		env->flags[flag] = 1;
	else
		env->values[flag] = atoi_(env, s, flag);
}

void	set_flags(t_env *env, const char *s)
{
	t_flags	flag;

	while (s[env->i] && (get_flags(s[env->i]) != ERROR || is_digit(s[env->i])))
	{
		flag = get_flags(s[env->i]);
		if (flag != ERROR)
			set_all_flags(env, flag, s);
		else
		{
			if (env->last_flag != DOT && env->last_flag && \
					env->flags[env->last_flag] && !env->values[env->last_flag])
				env->values[env->last_flag] = atoi_(env, s, env->last_flag);
			else
				env->values[LENGTH] = atoi_(env, s, LENGTH);
		}
	}
}

void	init_flags(t_env *env)
{
	int	i;

	i = -1;
	while (++i < ERROR)
		env->flags[i] = 0;
	env->values[DASH] = 0;
	env->values[LENGTH] = 0;
	env->last_flag = LENGTH;
}

void	left_jutify(t_env *env)
{
	int	n;

	if (!env->flags[DASH] || env->len == -1)
		return ;
	n = env->len - env->start_len;
	while (env->values[DASH]-- > n)
		put_char(env, ' ', 0);
}
