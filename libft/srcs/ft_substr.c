/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:17:05 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/08 09:17:06 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = malloc(len * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		res[i] = s[i + start];
		i++;
	}
	return (res);
}
