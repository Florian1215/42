/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:09:37 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/23 15:09:39 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	int		i;
	char	*content;

	if (ac == 1)
	{
		content = ft_stdin();
		ft_solve_map(content);
	}
	i = 1;
	while (i < ac)
	{
		content = ft_read_file(av[i]);
		ft_solve_map(content);
		i++;
	}
	free(content);
	return (0);
}
