/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solve3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:32:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/06 18:32:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int n)
{
	return (n * (-1 * (n < 0) + (n > 0)));
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_move(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (max(abs(a), abs(b)));
	return (abs(a) + abs(b));
}
