/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:52 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:53 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_mandelbrot(t_mlx *mlx)
{
	mlx->fractal.set = MANDELBROT;
	mlx->fractal.start = init_complex(-2.2, -2);
	mlx->fractal.end = init_complex(1.8, 2);
	mlx->fractal.sequence = mandelbrot;
	mlx->fractal.coor = coor_mandelbrot;
	mlx->fractal.color = GREEN;
	mlx->fractal.diff = 20;
	mlx->fractal.name = "Mandelbrot";
}

static void	set_julia(t_mlx *mlx)
{
	mlx->fractal.set = JULIA;
	mlx->fractal.start = init_complex(-2, -2);
	mlx->fractal.end = init_complex(2, 2);
	mlx->fractal.sequence = julia;
	mlx->fractal.coor = coor_julia;
	mlx->fractal.color = PURPLE;
	mlx->fractal.name = "Julia";
	mlx->fractal.diff = 15;
	set_preset(mlx, PRESET_1);
}

static void	set_celtic(t_mlx *mlx)
{
	mlx->fractal.set = CELTIC;
	mlx->fractal.start = init_complex(-2, 1.3);
	mlx->fractal.end = init_complex(2, -2.7);
	mlx->fractal.sequence = celtic;
	mlx->fractal.coor = coor_celtic;
	mlx->fractal.color = BLUE;
	mlx->fractal.name = "Celtic";
	mlx->fractal.diff = 18;
}

void	set_fractal(t_mlx *mlx, t_fractals set)
{
	static void	(*fractals_set[6])(t_mlx *) = {set_mandelbrot, set_julia, set_celtic, set_burning_shipe, set_buffalo, set_burning_julia};

	if (!mlx->in_menu)
		init_hover(mlx);
	set_preset(mlx, PRESET_0);
	fractals_set[set](mlx);
	mlx->fractal.max_iter = 50;
}
