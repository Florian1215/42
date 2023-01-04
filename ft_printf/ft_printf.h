/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:15:50 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/25 12:15:52 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long int	t_llu;
typedef enum e_conversions		t_conversions;
typedef enum e_flags			t_flags;
typedef enum e_bases			t_bases;
typedef struct s_base			t_base;
typedef struct s_env			t_env;

enum e_conversions
{
	CHAR = 'c',
	STRING = 's',
	POINTER = 'p',
	DIGIT = 'd',
	INTEGER = 'i',
	UNSIGNED = 'u',
	HEXA = 'X',
	PERCENT = '%',
};

enum e_flags
{
	HASHTAG = '#',
	PLUS = '+',
	MINUS = '-',
	SPACE = ' ',
	ZERO = '0',
	DOT = '.',
};

enum e_bases
{
	DEC,
	HEX_L,
	HEX_U,
};

struct s_base
{
	char	*base;
	t_llu	len;
};

struct s_env
{
	int	i;
	int	len;
	int	hashtag;
	int	space;
	int	zero;
	int	plus;
	int	minus;
	int	left_justify;
	int	start_len;
	int	dot;
	int	precision;
	int	value;
};

int		ft_printf(const char *format, ...);
void	put_char(t_env *env, int c);
void	put_str(t_env *env, char *s);
void	put_unsigned(t_env *env, t_llu nb, t_bases b, int decrease_value);
void	put_nbr_base(t_env *env, int n);
void	put_hexa(t_env *env, t_llu nb, int upper);
void	left_jutify(t_env *env);
int		to_upper(int c);
int		is_upper(int c);
void	init_flags(t_env *env);
void	set_flags(t_env *env, const char *str);
int		is_flags(int c);
int		is_conversion(int c);
int		is_digit(int c);

#include <stdio.h>

#endif
