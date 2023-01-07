/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_celtic_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:38:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:38:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_yellow(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0xE8AD80}, {0xCF784C}, {0xAD5845}, {0x73383E}};
	static t_appearance	app = -1;

	//0xF5E5BF - 0XF7FFed
	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0xF5E5BF;
		app = new_app;
	}
	return (pal);
}

static t_co	preset_celtic_mandelbrot(t_preset preset)
{
	static double	presets[6][2] = {
	{-0.816000, 0.128000},
	{-0.804000, -0.320000},
	{-1.184000, -0.252000},
	{-0.872000, -0.804000},
	{-0.562000, -1.044000},
	{-1.260000, -0.008000},
	};

	return (init_complex(presets[preset][0], presets[preset][1]));
}

void	set_celtic_mandelbrot(t_mlx *mlx)
{
	mlx->fractal.set = CELTIC_MANDELBROT;
	mlx->fractal.sequence = celtic_mandelbrot;
	mlx->fractal.offset_coor = init_complex(-125, -125);
	mlx->fractal.start_animation = init_complex(-2, 2);
	mlx->fractal.preset = preset_celtic_mandelbrot;
	mlx->fractal.max_preset = PRESET_5;
	mlx->fractal.color = YELLOW;
	mlx->fractal.name = "Celtic Mandelbrot";
	mlx->fractal.offset_name = 60;
}

int	celtic_mandelbrot(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = 2 * z.x * z.y + frac.c.y;
		z.x = fabs(sqr.x - sqr.y) + frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}
