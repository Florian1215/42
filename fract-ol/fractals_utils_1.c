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

void	launch_fractal(t_mlx *mlx, t_fractals set)
{
	mlx->in_menu = FALSE;
	mlx->c_animate = TRUE;
	mlx->launch = (set == MANDELBROT || set == BURNING_SHIP);
	set_fractal(mlx, set);
	set_color(mlx, mlx->fractal.color);
	set_preset(mlx, PRESET_0);
}

static t_co	preset_default(t_preset preset)
{
	(void)preset;
	return (init_complex(0, 0));
}

void	set_fractal(t_mlx *mlx, t_fractals set)
{
	static void	(*fractals_set[12])(t_mlx *) = {set_mandelbrot, set_julia, \
		set_celtic, set_burning_shipe, set_buffalo, set_burning_julia, \
		set_julia3, set_celtic_mandelbar, set_perpendicular_celtic, \
		set_heart, set_mandelbar, set_celtic_mandelbrot};

	if (!mlx->in_menu)
		init_hover(mlx);
	mlx->fractal.size_zoom = 1.6;
	mlx->fractal.start = init_complex(-2, 2);
	mlx->fractal.end = init_complex(2, -2);
	if (mlx->c_animate)
		mlx->fractal.start_animation = init_complex(0, -2);
	mlx->fractal.preset = preset_default;
	fractals_set[set](mlx);
	mlx->fractal.start_launch = mlx->fractal.start;
	mlx->fractal.end_launch = mlx->fractal.end;
	mlx->fractal.max_iter = 50;
	if (mlx->c_animate)
		mlx->fractal.c = mlx->fractal.start_animation;
	else
		set_preset(mlx, PRESET_0);
}

void	set_preset(t_mlx *mlx, t_preset preset)
{
	if (mlx->fractal.max_preset < preset)
		return ;
	if (mlx->in_menu || mlx->slide.slide)
		mlx->fractal.c = mlx->fractal.preset(preset);
	else
	{
		mlx->fractal.start_animation = mlx->fractal.c;
		mlx->fractal.end_animation = mlx->fractal.preset(preset);
		if (mlx->fractal.start_animation.x != mlx->fractal.end_animation.x && mlx->fractal.start_animation.y != mlx->fractal.end_animation.y)
			mlx->c_animate = TRUE;
	}
}
