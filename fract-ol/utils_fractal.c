/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:49:36 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/10 10:49:37 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	cross_multi(double start, double end, double scale)
{
	return (start + ((end - start) * scale));
}

void	move(t_mlx *mlx, enum e_keycode side)
{
	double	xy;
	int		i;

	i = 1;
	if (side == RIGHT || side == DOWN)
		i = -1;
	if (side == RIGHT || side == LEFT)
	{
		xy = fabs(mlx->zoom.end.x - mlx->zoom.start.x) * 0.02 * i;
		mlx->zoom.start.x += xy;
		mlx->zoom.end.x += xy;
	}
	else
	{
		xy = fabs(mlx->zoom.end.y - mlx->zoom.start.y) * 0.02 * i;
		mlx->zoom.start.y += xy;
		mlx->zoom.end.y += xy;
	}
	fractol(mlx);
}

void	zoom(t_mlx *mlx, double scale, t_co co)
{
	mlx->zoom.start.x = cross_multi(co.x, mlx->zoom.start.x, scale);
	mlx->zoom.start.y = cross_multi(co.y, mlx->zoom.start.y, scale);
	mlx->zoom.end.x = cross_multi(co.x, mlx->zoom.end.x, scale);
	mlx->zoom.end.y = cross_multi(co.y, mlx->zoom.end.y, scale);
	fractol(mlx);
}

void	edit_iter(t_mlx *mlx, int iter)
{
	int	res;

	res = mlx->max_iter + iter;
	if (res > 500 || res < 10)
		return ;
	mlx->max_iter = res;
	fractol(mlx);
}
