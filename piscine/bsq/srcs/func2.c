/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:42:50 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/24 10:42:51 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_isprintable(char c)
{
	return (c >= ' ' && c <= 126);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(src, '\0') + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

void	ft_clear_buffer(char *str)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		str[i] = '\0';
		i++;
	}
}
