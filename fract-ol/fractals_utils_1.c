/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:40:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 18:40:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fractal(t_mlx *mlx, t_fractals set)
{
	static void	(*fractals_set[12])(t_mlx *) = {set_mandelbrot, set_julia, \
		set_celtic, set_burning_shipe, set_buffalo, set_burning_julia, \
		set_julia3, set_celtic_mandelbar, set_perpendicular_celtic, \
		set_heart, set_mandelbar, set_celtic_mandelbrot};

	if (!mlx->in_menu)
		init_hover(mlx);
	set_preset(mlx, PRESET_0);
	fractals_set[set](mlx);
	mlx->fractal.max_iter = 50;
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
	printf("%f, %f\n", mlx->fractal.c.x, mlx->fractal.c.y);
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
