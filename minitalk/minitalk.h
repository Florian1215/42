/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:22:05 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 14:32:58 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>

char	*ft_dec(void);
char	*ft_hex(void);
char	*ft_hex_u(void);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putunsigned(unsigned long long int nb,
			char *base, int n_base, int *len);
void	ft_putnbr_base(int n, int *len);
void	ft_putstr(char *s, int *len);

# include <stdio.h>

#endif