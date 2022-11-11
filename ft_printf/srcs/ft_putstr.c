/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:09:15 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/10 09:09:15 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++], len);
	return (i);
}
