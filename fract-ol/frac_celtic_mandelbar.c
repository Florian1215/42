/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_celtic_mandelbar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:37:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:37:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_blue_light(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0x8ECDE6}, {0x66A1FF}, {0x6B61FF}, {0xFADDA2}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0xF0EFF4;
		app = new_app;
	}
	return (pal);
}

static t_co	preset_celtic_mandelbar(t_preset preset)
{
	static double	presets[9][2] = {
	{-0.78, -0.18},
	{-0.78, 0.12},
	{-0.032, 0.332},
	{-0.762, -0.248},
	{-0.44, -0.86},
	{-0.78, 0.10},
	{-0.49, -0.93},
	{-0.762, -0.128},
	{-0.926, 0.25},
	};

	return (init_complex(presets[preset][0], presets[preset][1]));
}

void	set_celtic_mandelbar(t_mlx *mlx)
{
	mlx->fractal.set = CELTIC_MANDELBAR;
	mlx->fractal.sequence = celtic_mandelbrot;
	mlx->fractal.offset_coor = init_complex(-125, -130);
	mlx->fractal.preset = preset_celtic_mandelbar;
	mlx->fractal.max_preset = PRESET_8;
	mlx->fractal.color = BLUE_LIGHT;
	mlx->fractal.name = "Celtic Mandelbar";
	mlx->fractal.offset_name = 50;
	mlx->fractal.size_zoom = 1.7;
}

int	celtic_mandelbar(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = -2 * z.x * z.y + frac.c.y;
		z.x = fabs(sqr.x - sqr.y) + frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}
