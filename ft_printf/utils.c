/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:18:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/05 10:18:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

t_bool	is_upper(int c)
{
	return (c > 'A' && c < 'Z');
}

int	to_upper(int c)
{
	return (c + (('A' - 'a') * !is_upper(c)));
}

t_flags	get_flags(int c)
{
	static char	flags[6] = "0-.#+ ";
	int			i;

	i = -1;
	while (++i < 6)
		if (c == flags[i])
			return (i + 1);
	return (ERROR);
}
