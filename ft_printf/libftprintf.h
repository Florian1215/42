/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:21:13 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/11 10:21:13 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *len);
void	ft_putunsigned(unsigned long long int nb,
			char *base, int n_base, int *len);
void	ft_putnbr_base(int n, int *len);
void	ft_putstr(char *s, int *len);

#endif