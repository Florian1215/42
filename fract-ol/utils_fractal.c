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

void	zoom(t_mlx *mlx, double scale, t_co co)
{
	if (scale < 1)
		mlx->max_iter += 0.7;
	else if (scale > 1)
		mlx->max_iter -= 0.7;
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
	printf("x = %f - y = %f\n", mlx->c.x, mlx->c.y);
	fractal_render(mlx);
}

void	edit_iter(t_mlx *mlx, double j)
{
	double	res;

	res = mlx->max_iter + j;
	if (res < 10 || res > 500)
		return ;
	mlx->max_iter = res;
	fractal_render(mlx);
}

t_fractal	init_fractal(t_fractals set, t_co start, t_co end, \
	int (*func)(t_mlx *, t_co, t_colors), t_colors color)
{
	t_fractal	frac;

	frac.set = set;
	frac.start = start;
	frac.end = end;
	frac.func = (int (*)(void *, t_co, t_colors))func;
	frac.color = color;
	return (frac);
}
