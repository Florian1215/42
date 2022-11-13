/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:48:14 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/08 08:49:05 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (count && size > SIZE_MAX / count)
		return (0);
	dest = malloc(size * count);
	if (!dest)
		return (0);
	ft_bzero(dest, count * size);
	return (dest);
}
