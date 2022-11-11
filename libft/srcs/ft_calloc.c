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

void	*calloc(size_t count, size_t size)
{
	void	*dest;

	dest = (void *)malloc(size * count);
	if (!dest)
		return (0);
	ft_bzero(dest, count);
	return (dest);
}
