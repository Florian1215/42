/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:38:04 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/15 16:24:04 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (0);
	range = malloc((max - min) * sizeof(int));
	i = 0;
	while (i + min < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
