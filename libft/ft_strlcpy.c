/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:03:29 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/08 09:03:31 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		srcsize;
	size_t	i;

	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	if (dstsize > 0)
	{
		i = -1;
		while (src[++i] != '\0' && i < (dstsize - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (srcsize);
}
