/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:28:31 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/14 11:58:09 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_strswap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_str_tab(char **tab, int size)
{
	char	*s2;
	int		i;
	int		j;

	if (size < 2)
		return ;
	s2 = tab[--size];
	i = 0;
	j = -1;
	while (++j < size)
		if (ft_strcmp(tab[j], s2) < 0)
			ft_strswap(&tab[i++], &tab[j]);
	if (ft_strcmp(tab[i], tab[size]) > 0)
		ft_strswap(&tab[i], &tab[size]);
	ft_sort_str_tab(tab, i);
	ft_sort_str_tab(tab + i + 1, size - i);
}

int	main(int ac, char **av)
{
	int	i;

	ft_sort_str_tab(av + 1, ac - 1);
	i = 0;
	while (++i < ac)
	{
		while (*av[i])
			ft_putchar(*av[i]++);
		ft_putchar('\n');
	}
	return (0);
}
