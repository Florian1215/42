/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_fractals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:54:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/07 16:54:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	cross_product(double a, double b, int i)
{
	static double	values[29] = {0.4, 1.7, 4.6, 9.8, 19, 32, 44.7, 54.7, 62.4, 68.6, 73.6, 77.7, 81.2, 84.2, 86.8, 89, 90.9, 92.5, 93.9, 95.2, 96.2, 97.1, 97.8, 98.5, 99, 99.4, 99.6, 99.8, 99.9};

	if (a > b)
		return (a - (values[i] * (a - b) / 100));
	else if (a < b)
		return ((values[i] * (b - a) / 100) + a);
	return (a);
}

void	reset_animation(t_mlx *mlx)
{
	static int		i = 0;

	if (i == 0)
	{
		mlx->fractal.start_animation = mlx->fractal.start;
		mlx->fractal.end_animation = mlx->fractal.end;
		mlx->fractal.max_iter = 50;
	}
	else if (i == 29)
	{
		mlx->reset = FALSE;
		i = 0;
		return ;
	}
	mlx->fractal.start.x = cross_product(mlx->fractal.start_animation.x, mlx->fractal.start_launch.x, i);
	mlx->fractal.start.y = cross_product(mlx->fractal.start_animation.y, mlx->fractal.start_launch.y, i);
	mlx->fractal.end.x = cross_product(mlx->fractal.end_animation.x, mlx->fractal.end_launch.x, i);
	mlx->fractal.end.y = cross_product(mlx->fractal.end_animation.y, mlx->fractal.end_launch.y, i);
	fractal_render(mlx);
	i++;
}

void	c_animation(t_mlx *mlx)
{
	static int		i = 0;

	if (i == 29 || (mlx->launch && mlx->fractal.c.y > 0))
	{
		i = 0;
		mlx->c_animate = FALSE;
		mlx->launch = FALSE;
		mlx->fractal.c = mlx->fractal.end_animation;
		fractal_render(mlx);
		return ;
	}
	if (mlx->launch)
		return (edit_c(mlx, mlx->fractal.c.y < -0.4 ? 0.07 : 0.03, &mlx->fractal.c.y));
	mlx->fractal.c.y = cross_product(mlx->fractal.start_animation.y, mlx->fractal.end_animation.y, i);
	mlx->fractal.c.x = cross_product(mlx->fractal.start_animation.x, mlx->fractal.end_animation.x, i);
	fractal_render(mlx);
	i++;
}
