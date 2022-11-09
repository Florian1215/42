/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:38:57 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 12:03:10 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	t_dict	*d;
	char	*path;
	char	*nb;
	char	*read_dict;

	if (!ft_check_args(ac, av, &path, &nb) || !ft_check_nb(nb))
		ft_error(0);
	else
	{
		read_dict = ft_read_file(path);
		if (read_dict)
		{
			d = ft_dict_create(read_dict);
			free(read_dict);
			if (d)
			{
				ft_print(d, nb);
				ft_dict_clear(d);
			}
		}
		else
			ft_error(1);
	}
	return (0);
}
