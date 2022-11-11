/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:00:23 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/08 09:01:36 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < dstsize && *dst)
		dst++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	j = -1;
	while (src[++j])
		if (j < dstsize - i - 1)
			*dst++ = src[j];
	*dst = '\0';
	return (i + j);
}
