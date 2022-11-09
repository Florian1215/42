/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:38:17 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/15 16:39:22 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	*range = 0;
	if (min >= max)
		return (0);
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (-1);
	i = 0;
	*range = tab;
	while (i + min < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (max - min);
}
