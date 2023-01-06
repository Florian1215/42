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
	mlx->fractal.size_zoom = 1.6;
	mlx->fractal.start = init_complex(-2, 2);
	mlx->fractal.end = init_complex(2, -2);
	fractals_set[set](mlx);
	set_preset(mlx, PRESET_0);
	mlx->fractal.max_iter = 50;
}

void	set_preset(t_mlx *mlx, t_preset preset)
{
	if (mlx->fractal.max_preset < preset)
		return ;
	mlx->fractal.c = mlx->fractal.preset(preset);
	if (mlx->launch)
		mlx->fractal.c.y -= 2;
	if (!mlx->in_menu)
		fractal_render(mlx);
}

t_co	preset_default(t_preset preset)
{
	(void)preset;
	return (init_complex(0, 0));
}
