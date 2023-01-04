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

t_bool	is_conversion(int c)
{
	return (c == CHAR || c == STRING || c == DIGIT || to_upper(c) == HEXA || \
		c == UNSIGNED || c == INTEGER || c == POINTER || c == PERCENT);
}

t_bool	is_flags(int c)
{
	return ((c == HASHTAG) || c == SPACE || c == ZERO || c == PLUS || \
		c == MINUS || c == DOT);
}

t_bool	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

//static t_bool	find_flag_dot(t_env *env, const char *str)
//{
//	int	i;
//
//	i = env->i - 1;
//	while (str[++i] && is_flags(str[i]))
//	{
//		if (str[i] == ZERO || str[i] == MINUS || str[i] == SPACE || str[i] == PLUS)
//			while (str[i] && is_digit(str[i]))
//				i++;
//		if (str[i] == DOT)
//			return (TRUE);
//	}
//	return (FALSE);
//}

static int	atoi_(t_env *env, const char *str, int *var)
{
	int	res;

	res = 0;
	if (var)
		env->i++;
	if (str[env->i] != '0' || var != NULL)// || find_flag_dot(env, str))
		while (str[env->i] && is_digit(str[env->i]))
			res = res * 10 + str[env->i++] - '0';
	env->i--;
	if (var)
		*var = 1;
	return (res);
}

void	set_flags(t_env *env, const char *str)
{
	while (str[env->i] && (is_flags(str[env->i]) || (env->value == -1 && is_digit(str[env->i]))))
	{
		if (str[env->i] == HASHTAG)
			env->hashtag = 1;
		else if (str[env->i] == PLUS)
			env->plus = 1;
		else if (str[env->i] == SPACE)
			env->space = 1;
		else if (str[env->i] == ZERO)
			env->nb_zero = atoi_(env, str, &env->zero);
		else if (str[env->i] == MINUS)
			env->left_justify = atoi_(env, str, &env->minus);
		else if (str[env->i] == DOT)
		{
			env->precision = atoi_(env, str, &env->dot);
			if (env->zero && env->nb_zero)
			{
				env->zero = 0;
				env->value = env->nb_zero;
			}
		}
		else if (is_digit(str[env->i]))
		{
			if (!env->left_justify && env->minus)
			{
//				printf("%d - '%c'\n", env->left_justify, str[env->i]);
				env->i--;
				env->left_justify = atoi_(env, str, &env->minus);
				env->i++;
//				printf("%d\n", env->left_justify);
			}
			if (!env->nb_zero && env->zero)
			{
				env->i--;
				env->nb_zero = atoi_(env, str, &env->zero);
			}
			else
				env->value = atoi_(env, str, NULL);
		}
//		printf("\n%d %d\n", env->left_justify, env->value);
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
	env->value = -1;
	env->left_justify = 0;
}

void	left_jutify(t_env *env)
{
	int	n;

//	printf("\n%d - %d\n", env->len, env->left_justify);
	if (!env->minus || env->len == -1)
		return ;
	n = env->len - env->start_len;
	while (env->left_justify-- > n)
		put_char(env, ' ', FALSE);
}
