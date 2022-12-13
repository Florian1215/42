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
	if (side == RIGHT || (side == DOWN && (mlx->fractal.set == MANDELBROT || \
		mlx->fractal.set == JULIA)) || (side == UP && (mlx->fractal.set \
		== BURNING_SHIP || mlx->fractal.set == CELTIC)))
		i = -1;
	if (side == RIGHT || side == LEFT)
	{
		xy = fabs(mlx->fractal.end.x - mlx->fractal.start.x) * 0.02 * i;
		mlx->fractal.start.x += xy;
		mlx->fractal.end.x += xy;
	}
	else
	{
		xy = fabs(mlx->fractal.end.y - mlx->fractal.start.y) * 0.02 * i;
		mlx->fractal.start.y += xy;
		mlx->fractal.end.y += xy;
	}
	fractal_render(mlx);
}

void	zoom(t_mlx *mlx, double scale, t_co co)
{
	if (scale < 1)
		mlx->max_iter += 0.5;
	else if (scale > 1)
		mlx->max_iter -= 0.5;
	mlx->fractal.start.x = cross_multi(co.x, mlx->fractal.start.x, scale);
	mlx->fractal.start.y = cross_multi(co.y, mlx->fractal.start.y, scale);
	mlx->fractal.end.x = cross_multi(co.x, mlx->fractal.end.x, scale);
	mlx->fractal.end.y = cross_multi(co.y, mlx->fractal.end.y, scale);
	fractal_render(mlx);
}

void	edit_c(t_mlx *mlx, double j, double *nb)
{
	double	res;

	res = *nb + j;
	if (res < -2 || res > 2)
		return ;
	*nb = res;
	fractal_render(mlx);
}

t_fractal	init_fractal(t_fractals set, t_co start, t_co end, \
	int (*func)(t_mlx *, t_co), t_colors color)
{
	t_fractal	frac;

	frac.set = set;
	frac.start = start;
	frac.end = end;
	frac.func = (int (*)(void *, t_co))func;
	frac.color = color;
	return (frac);
}
