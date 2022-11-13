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

	if (!(char *)dst || !(char *)src)
		return (0);
	i = 0;
	if (dst > src)
		while (++i <= n)
			*(char *)(dst + (n - i)) = *(char *)(src + (n - i));
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
