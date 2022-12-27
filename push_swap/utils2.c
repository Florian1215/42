/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:35:33 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 17:26:27 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str && str[len] != '\0')
		len++;
	return (len);
}

void	move_up(int *stack, int *len)
{
	int	i;

	i = -1;
	*len -= 1;
	while (++i < *len)
		stack[i] = stack[i + 1];
}

void	move_down(int *stack, int *len)
{
	int	i;

	i = 0;
	while (++i <= *len)
		stack[*len - i + 1] = stack[*len - i];
	*len += 1;
}
