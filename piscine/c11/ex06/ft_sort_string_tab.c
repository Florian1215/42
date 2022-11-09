/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:53:07 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/19 11:19:53 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int	n;

	n = 0;
	while (tab[n])
		n++;
	ft_sort_str_tab(tab, n);
}
