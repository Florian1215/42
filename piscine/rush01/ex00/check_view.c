/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:55:34 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/14 22:36:50 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#define N_SIZE 4

int	ft_colup(int tab[N_SIZE][N_SIZE], int pos, int entry[N_SIZE *4]);
int	ft_coldown(int tab[N_SIZE][N_SIZE], int pos, int entry[N_SIZE *4]);
int	ft_rowleft(int tab[N_SIZE][N_SIZE], int pos, int entry[N_SIZE *4]);
int	ft_rowright(int tab[N_SIZE][N_SIZE], int pos, int entry[N_SIZE *4]);
int	ft_check_view(int tab[N_SIZE][N_SIZE], int pos, int *entry);

int	ft_colup(int tab[N_SIZE][N_SIZE], int pos, int entry[N_SIZE *4])
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	if (pos / N_SIZE == N_SIZE - 1)
	{
		while (i < N_SIZE)
		{
			if (tab[i][pos % N_SIZE] > max)
			{
				max = tab[i][pos % N_SIZE];
				count += 1;
			}
			i++;
		}
		if (count != entry[pos % N_SIZE])
			return (1);
	}
	return (0);
}

int	ft_coldown(int tab[N_SIZE][N_SIZE], int pos, int entry[N_SIZE *4])
{
	int	i;
	int	count;
	int	max;

	i = N_SIZE - 1;
	count = 0;
	max = 0;
	if (pos / N_SIZE == N_SIZE - 1)
	{
		while (i >= 0)
		{
			if (tab[i][pos % N_SIZE] > max)
			{
				max = tab[i][pos % N_SIZE];
				count += 1;
			}
			i--;
		}
		if (count != entry[N_SIZE + pos % N_SIZE])
			return (1);
	}
	return (0);
}

int	ft_rowleft(int tab[N_SIZE][N_SIZE], int pos, int entry[N_SIZE *4])
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	if (pos % N_SIZE == N_SIZE - 1)
	{
		while (i < N_SIZE)
		{
			if (tab[pos / N_SIZE][i] > max)
			{
				max = tab[pos / N_SIZE][i];
				count += 1;
			}
			i++;
		}
		if (count != entry[(N_SIZE * 2) + pos / N_SIZE])
			return (1);
	}
	return (0);
}

int	ft_rowright(int tab[N_SIZE][N_SIZE], int pos, int entry[N_SIZE *4])
{
	int	i;
	int	count;
	int	max;

	i = N_SIZE - 1;
	count = 0;
	max = 0;
	if (pos % N_SIZE == N_SIZE - 1)
	{
		while (i >= 0)
		{
			if (tab[pos / N_SIZE][i] > max)
			{
				max = tab[pos / N_SIZE][i];
				count += 1;
			}
			i--;
		}
		if (count != entry[(N_SIZE * 3) + pos / N_SIZE])
			return (1);
	}
	return (0);
}

int	ft_check_view(int tab[N_SIZE][N_SIZE], int pos, int *entry)
{
	if (ft_colup(tab, pos, entry))
		return (0);
	if (ft_coldown(tab, pos, entry))
		return (0);
	if (ft_rowleft(tab, pos, entry))
		return (0);
	if (ft_rowright(tab, pos, entry))
		return (0);
	return (1);
}
