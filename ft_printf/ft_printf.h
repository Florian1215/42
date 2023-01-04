/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:57:23 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/04 16:39:39 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long int	t_llu;
typedef enum e_bool				t_bool;
typedef enum e_conversions		t_conversions;
typedef enum e_flags			t_flags;
typedef enum e_bases			t_bases;
typedef struct s_base			t_base;
typedef struct s_env			t_env;

enum e_bool
{
	FALSE,
	TRUE,
};

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
	HEX,
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
	int	nb_zero;
	int	plus;
	int	minus;
	int	left_justify;
	int	start_len;
	int	dot;
	int	precision;
	int	value;
};

int		ft_printf(const char *format, ...);
void	put_char(t_env *env, int c, t_bool preci);
void	put_str(t_env *env, char *s);
void	put_u(t_env *env, t_llu nb);
void	put_unsigned(t_env *env, t_llu nb, t_bases b);
void	put_nbr_base(t_env *env, int n);
void	put_hexa(t_env *env, t_llu nb, t_bool upper);
int		nb_len(t_llu nb, t_llu len_base);
void	left_jutify(t_env *env);
int		to_upper(int c);
t_bool	is_upper(int c);
void	init_flags(t_env *env);
void	set_flags(t_env *env, const char *str);
t_bool	is_flags(int c);
t_bool	is_conversion(int c);
t_bool	is_digit(int c);

#include <stdio.h>

#endif
