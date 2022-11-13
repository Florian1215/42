/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:17:05 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/12 16:54:24 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	res = malloc(len * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
