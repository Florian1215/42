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

// INCLUDE --------------------------------------------------
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

// TYPEDEF --------------------------------------------------
typedef unsigned long long int	t_llu;
typedef enum e_flags			t_flags;
typedef enum e_bases			t_bases;
typedef struct s_base			t_base;
typedef struct s_env			t_env;

// FLAGS ----------------------------------------------------
enum e_flags
{
	LENGTH,
	ZERO,
	DASH,
	DOT,
	HASHTAG,
	PLUS,
	SPACE,
	ERROR,
};

void	init_flags(t_env *env);
void	set_flags(t_env *env, const char *str);
void	put_nb_flags(t_env *env, t_llu nb, int unsign, t_bases b);
void	left_jutify(t_env *env);

// MAIN -----------------------------------------------------
struct s_env
{
	int		i;
	int		len;
	int		start_len;
	t_flags	last_flag;
	int		flags[7];
	int		values[4];
};

int		ft_printf(const char *format, ...);

// CHAR -----------------------------------------------------
void	put_char(t_env *env, int c, int preci);
void	put_str(t_env *env, char *s);

// NUMBER ---------------------------------------------------
enum e_bases
{
	DEC,
	HEX,
	HEX_UPPER,
	HEX_POINTER,
};

struct s_base
{
	char	*base;
	t_llu	len;
};

void	put_nbr_base(t_env *env, int n);
void	put_unsigned(t_env *env, t_llu nb, t_bases b);
void	put_u(t_env *env, t_llu nb);
void	put_hexa(t_env *env, t_llu nb, int upper);

// UTILS ----------------------------------------------------
int		to_upper(int c);
int		is_upper(int c);
t_flags	get_flags(int c);
int		is_digit(int c);

#endif
