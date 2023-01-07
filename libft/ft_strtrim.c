/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:29:48 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/08 16:29:50 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	to;

	st = 0;
	while (s1[st] && ft_strchr(set, s1[st]))
		st++;
	to = ft_strlen((char *)s1) - 1;
	while (s1[to] && ft_strrchr(set, s1[to]) && to > st)
		to--;
	return (ft_substr(s1, st, ++to - st));
}
