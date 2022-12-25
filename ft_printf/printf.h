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

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long int	t_llu;
typedef enum e_bases			t_bases;
typedef struct s_base			t_base;

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

int		ft_printf(const char *format, ...);
void	put_char(int c, int *len);
void	put_unsigned(t_llu nb, t_bases b, int *len);
void	put_nbr_base(int n, int *len);

#endif
