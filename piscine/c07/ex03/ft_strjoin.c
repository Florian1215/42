/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:38:32 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/23 16:46:22 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	k = 0;
	len = 1;
	while (k < size)
		len += ft_strlen(strs[k++]) + ft_strlen(sep);
	tab = malloc(sizeof(char *) * len);
	k = -1;
	while (++k < size)
	{
		j = 0;
		while (strs[k][j])
			tab[i++] = strs[k][j++];
		j = 0;
		while (sep[j] && k < size - 1)
			tab[i++] = sep[j++];
	}
	tab[i] = '\0';
	return (tab);
}
