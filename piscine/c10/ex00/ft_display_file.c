/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:02:07 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/17 18:35:53 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	ft_openfile(char *file_name)
{
	int		file;
	int		r;
	char	c;

	file = open(file_name, 0);
	if (file == -1)
		return (0);
	r = 1;
	while (r)
	{
		r = read(file, &c, 1);
		if (r == -1)
			return (0);
		else if (r)
			ft_putchar(c);
	}
	close(file);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_putstr("File name missing.\n");
	else if (ac > 2)
		ft_putstr("Too many arguments\n");
	else
	{
		if (!ft_openfile(av[1]))
			ft_putstr("Cannot read file.\n");
	}
	return (0);
}
