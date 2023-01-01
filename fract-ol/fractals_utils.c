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
		mlx->fractal.max_iter += 0.7;
	else if (scale > 1)
		mlx->fractal.max_iter -= 0.7;
	mlx->fractal.start.x = cross_multi(co.x, mlx->fractal.start.x, scale);
	mlx->fractal.start.y = cross_multi(co.y, mlx->fractal.start.y, scale);
	mlx->fractal.end.x = cross_multi(co.x, mlx->fractal.end.x, scale);
	mlx->fractal.end.y = cross_multi(co.y, mlx->fractal.end.y, scale);
	fractal_render(mlx);
}

void	set_preset(t_mlx *mlx, t_preset preset)
{
	static double	co[10][2] = {{0, 0}, \
							{0.80, 0}, \
							{0.75, 0.1}, \
							{0.78, -0.12}, \
							{0.78, -0.15}, \
							{1.15, 0.25}, \
							{0.8, -0.25}, \
							{0.74, 0.08}, \
							{0.8, -0.156}, \
							{0.76, 0.08}};

	mlx->fractal.c = init_complex(co[preset][0], co[preset][1] - (mlx->launch * 2));
	if (!mlx->in_menu)
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

void	edit_iter(t_mlx *mlx, double j)
{
	double	res;

	res = mlx->fractal.max_iter + j;
	if (res < 10 || res > 500)
		return ;
	mlx->fractal.max_iter = res;
	fractal_render(mlx);
}
