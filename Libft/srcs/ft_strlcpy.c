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

size_t
	strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		srcsize;
	size_t	i;

	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
