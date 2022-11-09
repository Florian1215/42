/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:49:54 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/16 16:59:27 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_len(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc((ft_len(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	if (ac < 0)
		ac = 0;
	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (0);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_len(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
