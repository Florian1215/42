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
	int	res;

	res = 0;
	while (s[env->i] && is_digit(s[env->i]))
		res = res * 10 + s[env->i++] - '0';
	if (flag != LENGTH)
		env->flags[flag] = 1;
	return (res);
}

static void	set_all_flags(t_env *env, t_flags flag, const char *s)
{
	if (flag > 3)
	{
		env->flags[flag] = 1;
		env->i++;
	}
	else
	{
		env->i++;
		env->values[flag] = atoi_(env, s, flag);
		if (flag == DOT && env->flags[ZERO] && env->values[ZERO])
		{
			env->flags[ZERO] = 0;
			env->values[LENGTH] = env->values[ZERO];
		}
	}
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
			if (env->flags[DASH] && !env->values[DASH])
				env->values[DASH] = atoi_(env, s, DASH);
			else if (env->flags[ZERO] && !env->values[ZERO])
				env->values[ZERO] = atoi_(env, s, ZERO);
			else if (env->values[LENGTH] == -1)
				env->values[LENGTH] = atoi_(env, s, LENGTH);
			else
				break ;
		}
	}
}

void	init_flags(t_env *env)
{
	env->flags[HASHTAG] = 0;
	env->flags[PLUS] = 0;
	env->flags[SPACE] = 0;
	env->flags[ZERO] = 0;
	env->flags[DASH] = 0;
	env->flags[DOT] = 0;
	env->values[DASH] = 0;
	env->values[LENGTH] = -1;
}

void	left_jutify(t_env *env)
{
	int	n;

	if (!env->flags[DASH] || env->len == -1)
		return ;
	n = env->len - env->start_len;
	while (env->values[DASH]-- > n)
		put_char(env, ' ', FALSE);
}
