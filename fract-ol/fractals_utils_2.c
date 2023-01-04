/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:40:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 18:40:00 by fguirama         ###   ########.fr       */
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

void	move(t_mlx *mlx, int x, int y)
{
	t_co	co;

	co.x = (mlx->prev_pos.x - x) / mlx->size * fabs(mlx->fractal.end.x - mlx->fractal.start.x);
	mlx->fractal.start.x += co.x;
	mlx->fractal.end.x += co.x;
	co.y = (mlx->fractal.set > 1 ? (mlx->prev_pos.y - y) : (y - mlx->prev_pos.y)) / mlx->size * fabs(mlx->fractal.end.y - mlx->fractal.start.y);
	mlx->fractal.start.y += co.y;
	mlx->fractal.end.y += co.y;
	fractal_render(mlx);
	mlx->prev_pos = init_complex(x, y);
}
