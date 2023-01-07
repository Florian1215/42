/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:17:05 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/07 16:21:56 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(s);
	if (start > str_len)
		len = 0;
	else if (len + start > str_len)
		len = str_len - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len && s[i])
		res[i] = s[i + start];
	return (res[i] = '\0', res);
}
