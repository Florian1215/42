/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:24:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/03 15:24:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_conversion(int c)
{
	return (c == CHAR || c == STRING || c == DIGIT || to_upper(c) == HEXA || \
		c == UNSIGNED || c == INTEGER || c == POINTER || c == PERCENT);
}

int	is_flags(int c)
{
	return (c == HASHTAG || c == SPACE || c == ZERO || c == PLUS || \
		c == MINUS || c == DOT);
}

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	atoi_(t_env *env, const char *str, int *var)
{
	int	res;

	res = 0;
	if (var)
		env->i++;
	while (str[env->i] && is_digit(str[env->i]))
		res = res * 10 + str[env->i++] - '0';
	if (var)
	{
		env->i--;
		*var = 1;
	}
	return (res);
}

void	set_flags(t_env *env, const char *str)
{
	env->value = atoi_(env, str, NULL);
	while (str[env->i] && is_flags(str[env->i]))
	{
		if (str[env->i] == HASHTAG)
			env->hashtag = 1;
		else if (str[env->i] == SPACE)
			env->space = 1;
		else if (str[env->i] == ZERO)
			env->zero = 1;
		else if (str[env->i] == PLUS)
			env->plus = 1;
		else if (str[env->i] == MINUS)
			env->left_justify = atoi_(env, str, &env->minus);
		else if (str[env->i] == DOT)
			env->precision = atoi_(env, str, &env->dot);
		env->i++;
	}
}

void	init_flags(t_env *env)
{
	env->hashtag = 0;
	env->space = 0;
	env->zero = 0;
	env->plus = 0;
	env->minus = 0;
	env->dot = 0;
	env->value = 0;
	env->left_justify = 0;
}
