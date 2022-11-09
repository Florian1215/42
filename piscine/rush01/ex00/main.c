/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:52:53 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/15 11:20:25 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define N_SIZE 4

void	ft_putchar(char c);
void	ft_print_solution(int tab[N_SIZE][N_SIZE]);
int		ft_find_solution(int tab[N_SIZE][N_SIZE], int *entry, int pos);
int		*ft_parsing(char *str);
int		main(int argc, char **argv);
int		ft_check_view(int tab[N_SIZE][N_SIZE], int pos, int *entry);
int		ft_check_double_rc(int tab[N_SIZE][N_SIZE], int pos, int nb);

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_solution(int tab[N_SIZE][N_SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < N_SIZE)
	{
		j = 0;
		while (j < N_SIZE)
		{
			ft_putchar(tab[i][j] + '0');
			if (j != N_SIZE - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_find_solution(int tab[N_SIZE][N_SIZE], int *entry, int pos)
{
	int	nb;

	if (pos == N_SIZE * N_SIZE)
		return (1);
	nb = 1;
	while (nb <= N_SIZE)
	{
		if (ft_check_double_rc(tab, pos, nb))
		{
			tab[pos / N_SIZE][pos % N_SIZE] = nb;
			if (ft_check_view(tab, pos, entry))
			{
				if (ft_find_solution(tab, entry, pos + 1))
					return (1);
			}
			else
				tab[pos / N_SIZE][pos % N_SIZE] = 0;
		}
		nb++;
	}
	return (0);
}

int	*ft_parsing(char *str)
{
	int	*entry;
	int	i;
	int	j;

	entry = malloc(sizeof(int) * (N_SIZE * 4));
	if (!entry)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(i % 2))
		{
			if (j < N_SIZE * 4 && str[i] >= '0' && str[i] <= '9')
				entry[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (j == N_SIZE * 4)
		return (entry);
	return (0);
}

int	main(int argc, char **argv)
{
	int	tab[N_SIZE][N_SIZE];
	int	*entry;
	int	i;
	int	j;

	if (argc != 2)
	{
		write(1, "Error", 6)
		return (0);
	}
	i = 0;
	j = 0;
	while (i < N_SIZE)
	{
		while (j < N_SIZE)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	entry = ft_parsing(argv[1]);
	if (entry && ft_find_solution(tab, entry, 0))
		ft_print_solution(tab);
	else
		write(1, "Error", 6);
	return (0);
}
