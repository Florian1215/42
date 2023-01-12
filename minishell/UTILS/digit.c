/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:07:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/11 18:07:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	atoi(char *nb, unsigned char *var)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = res * 10 + nb[i++] - '0';
		if (res > UCHAR_MAX)
			return (ERROR);
	}
	if (!i || str_len(nb) != i)
		return (ERROR);
	*var = (unsigned char)res;
	return (SUCCESS);
}
