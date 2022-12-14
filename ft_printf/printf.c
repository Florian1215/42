/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:11:12 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/01 11:55:39 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(t_env *env, int c, int preci)
{
	if (env->len == -1 || (preci && env->flags[DOT] && env->values[DOT] < 0))
		return ;
	if (env->values[LENGTH] > 0)
	{
		env->values[LENGTH]--;
		put_char(env, ' ', 0);
	}
	if (preci && env->flags[DOT])
		env->values[DOT]--;
	if (preci && env->flags[DOT] && env->values[DOT] < 0)
		return ;
	if (write(1, &c, 1) == -1)
		env->len = -1;
	else
		env->len += 1;
}

static void	format_str(t_env *env, char c, va_list	args)
{
	if (c == 's')
		return (put_str(env, va_arg(args, char *)));
	if (c == 'p')
		return (put_hexa(env, va_arg(args, t_llu), 2));
	if (c == 'u')
		return (put_u(env, va_arg(args, unsigned int)));
	if (c == 'd' || c == 'i')
		return (put_nbr_base(env, va_arg(args, int)));
	if (to_upper(c) == 'X')
		return (put_hexa(env, va_arg(args, unsigned int), is_upper(c)));
	env->values[LENGTH]--;
	env->values[DOT] = 1;
	if (c == 'c')
		return (put_char(env, va_arg(args, int), 1));
	put_char(env, c, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_env	env;

	va_start(args, format);
	env.len = 0;
	env.i = -1;
	while (format[++env.i] && env.len != -1)
	{
		init_flags(&env);
		if (format[env.i] == '%')
		{
			env.i++;
			set_flags(&env, format);
			if (!format[env.i])
				break ;
			env.start_len = env.len;
			format_str(&env, format[env.i], args);
			left_jutify(&env);
		}
		else
			put_char(&env, format[env.i], 0);
	}
	va_end(args);
	return (env.len);
}
