/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:57:42 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/08 08:58:29 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	int		step;

	if (!dst || !src)
		return (0);
	if (dst > src)
	{
		step = -1;
		i = n - 1;
	}
	else
	{
		step = 1;
		i = 0;
	}
	while ((step == 1 && i < n) || (step == -1 && i >= 0))
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i += step;
	}
	return (dst);
}
